#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int run_for_tr_check(float ti, float tf,float tc,float pi,float pf){
	float P_sat_initial,P_sat_final,my_value,shallu_val,Parul_initial,Parul_final;
	float A,B,C;
	float tri,trf;
	// if((ti/tc)>=3&&(tf/tc)>=3){
	// 	return 1;
	// }
	// else if((ti/tc)<=0.7){
	// 	//pressure check
	// 	//P_sat defined which takes in A,B,C and ti ,tf
	// 	//abc are user input
	// 	printf("enter A,B,C\n");
	// 	scanf("%f,%f,%f",&A,&B,&C);
	// 	my_value = A - (B/(ti+C));
	// 	P_sat_initial = pow(2.71,(my_value));
	// 	my_value = A - (B/(tf+C));
	// 	P_sat_final = pow(2.71,(my_value));
	// 	if(pi<P_sat_initial&&pf<P_sat_final){
	// 		return 1;
	// 	}
	// }
	// else if(((ti/tc)>0.7&&(tf/tc)>0.7)&&((ti/tc)<3&&(tf/tc)<3)){
	// 	printf("enter A,B,C\n");
	// 	scanf("%f,%f,%f",&A,&B,&C);
	// 	my_value = A - (B/(ti+C));
	// 	P_sat_initial = pow(2.71,(my_value));
	// 	my_value = A - (B/(tf+C));
	// 	P_sat_final = pow(2.71,(my_value));
	// 	Parul_initial = (3*(ti/tc)-2.1-(ti/tc)*(P_sat_initial)+3*P_sat_initial)/2.3;
	// 	Parul_final = (3*(tf/tc)-2.1-(tf/tc)*(P_sat_final)+3*P_sat_final)/2.3;
	// 	if(pi<Parul_initial&&pf<Parul_final){
	// 		return 1;
	// 	}
	// }
	// else return 0;






}
int main(){
	float r = 8.314;
	float cp_average_h ,cp_average_s,tau;
	float b01,b02,b11,b12;
	float pi,pf,ti,tf,tc,pc,w,a,b,c,d;//inputs
	float partial_b01,partial_b02,partial_b11,partial_b12;
	float h1r,delta_hig,h2r,delta_h,s1r,delta_sig,s2r,delta_s;
	printf("ENTER INPUT: Pi,Pf,Pc,Ti,Tf,Tc,omega,A,B,C,D::\n");
	scanf("%f,%f,%f,%f,%f,%f,%f,%f,%f,%f",&pi,&pf,&pc,&ti,&tf,&tc,&w,&a,&b,&c,&d);
	printf("inputs are :%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n",pi,pf,pc,ti,tf,tc,w,a,b,c,d);
	int val = run_for_tr_check(ti,tf,tc,pi,pf);
	if(val==1|1){
		b01 = (0.083-(0.422*pow((tc/ti),1.6)));
		b02 = (0.083-(0.422*pow((tc/tf),1.6)));
		b11 = (0.139-(0.172*pow((tc/ti),4.2)));
		b12 = (0.139-(0.172*pow((tc/tf),4.2)));
		partial_b01 = (0.675)*pow((tc/ti),2.6);
		partial_b02 = (0.675)*pow((tc/tf),2.6);
		partial_b11 = (0.722)*pow((tc/ti),5.2);
		partial_b12 = (0.722)*pow((tc/tf),5.2);
		h1r = ((r*tc)*(pi/pc))*((b01-((ti/tc)*partial_b01))+(w*(b11-((ti/tc)*partial_b11))));
		h2r = ((r*tc)*(pf/pc))*((b02-((tf/tc)*partial_b02))+(w*(b12-((tf/tc)*partial_b12))));
		s1r = (-1.0*(r*(pi/pc)))*(partial_b01+(w*partial_b11));
		s2r = (-1.0*(r*(pf/pc)))*(partial_b02+(w*partial_b12));
		tau = tf/ti;
		cp_average_h = r*((a+((b/2)*(ti*(1+tau))))+((((c/3)*pow(ti,2))*(pow(tau,2)+tau+1))+d/(tau*pow(ti,2))));
		cp_average_s = r*(a+(b*ti+((c*pow(ti,2))+d/(pow(tau*ti,2))*((tau+1)/2))*((tau-1)/log(tau))));
		delta_hig = cp_average_h*(tf-ti);
		delta_h = delta_hig + h2r - h1r;
		delta_sig = (cp_average_s*log(tf/ti))-r*(log(pf/pi));
		delta_s = delta_sig + s2r - s1r;
		printf("%f,%f,%f,%f,%f,%f,%f,%f,",delta_hig,h1r,h2r,delta_h,delta_sig,s1r,s2r,delta_s);
	}// 3000000,235000,22055000,723.15,413.15,647.1,0.345,3.47,0.00145,0,12100
	else {
		printf("INVALID\n");
	}

}
