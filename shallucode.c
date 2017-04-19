#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int run_for_tr_check(float ti, float tf,float tc,float pi,float pf,float pc,float alu,float balu,float shalu){
	float P_sat_initial,P_sat_final,my_value,shallu_val,Parul_initial,Parul_final;
	float A,B,C;
	float this_float;
	//printf("enter A,B,C\n");
	//scanf("%d",&this_float);
	//scanf("%f,%f,%f",&A,&B,&C);
	A = alu;
	B = balu;
	C = shalu;
	float tr0 = ti/tc;
	float tr1 = tf/tc;
	float pr0 = pi/pc;
  float pr1 = pf/pc;
	my_value = A - (B/(ti+C));
	P_sat_initial = pow(2.71,(my_value));
	my_value = A - (B/(tf+C));
	P_sat_final = pow(2.71,(my_value));
  float prsat=P_sat_initial/pc;
  Parul_initial = (3*(ti/tc)-2.1-(ti/tc)*(P_sat_initial)+3*P_sat_initial)/2.3;
  Parul_final = (3*(tf/tc)-2.1-(tf/tc)*(P_sat_final)+3*P_sat_final)/2.3;
	if(tr0>=3){
 // printf("check-----------------------\n");
		return 1;
	}
	else if(tr0<=0.7){
    if(pr0<prsat){
    return 1;
    }
    else return 0;
	}
  else if(tr0>0.7 && tr0<3){
    if(prsat<Parul_initial){
    	return 1;
    }
    else {
    return 0;
    }
  }
  prsat = P_sat_final/pc;
  if(tr1>=3){
		return 1;
	}
	else if(tr1<=0.7){
    if(pr1<prsat){
    return 1;
    }
    else return 0;
	}
  else if(tr1>0.7 && tr1<3){
    if(prsat<Parul_final){
    	return 1;
    }
    else {
    return 0;
    }
  }      
       	return 1;
       	//3405,4055,22000,706,606,809,0.444,3,0.9,122,9

}
int main(){
	float r = 8.314;
	float cp_average_h ,cp_average_s,tau;
	float b01,b02,b11,b12,alu,balu,shalu;
	float pi,pf,ti,tf,tc,pc,w,a,b,c,d;//inputs
	float partial_b01,partial_b02,partial_b11,partial_b12;
	float h1r,delta_hig,h2r,delta_h,s1r,delta_sig,s2r,delta_s;
	printf("ENTER INPUT: Pi,Pf,Pc,Ti,Tf,Tc,omega,A,B,C,D,conditional A,B,C::\n");
	scanf("%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n",&pi,&pf,&pc,&ti,&tf,&tc,&w,&a,&b,&c,&d,&alu,&balu,&shalu);
	//printf("inputs are :%f,%f,%f,%f,%f\n%f,%f,%f,%f,%f \n",pi,pf,pc,ti,tf,tc,w,a,b,c,d);
	int val = run_for_tr_check(ti,tf,tc,pi,pf,pc,alu,balu,shalu);
	 if(val==1){
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
		//cp_average_s = r*( a + ( ( tau-1 )/log(tau) )*( b*ti + ( ( c*pow(ti,2)+d/ ( pow(tau*ti,2) ) )*( ( tau+1 )/2 ) ) ) );
		cp_average_s = (r*(a+(b*ti+(c*pow(ti,2)+d/pow(tau*ti,2))*((tau+1)/2))*((tau-1)/log(tau))));
		delta_hig = 1.00943379*(cp_average_h*(tf-ti));
		delta_h = delta_hig + h2r - h1r;
		delta_sig = ((cp_average_s*log(tf/ti))-r*(log(pf/pi)));
		delta_s = delta_sig + s2r - s1r;
		printf("delta_hig:%f\n,h1r:%f\n,h2r:%f\n,delta_h:%f\n,delta_sig:%f\n,s1r:%f\n,s2r:%f\n,delta_s:%f\n,",delta_hig,h1r,h2r,delta_h,delta_sig,s1r,s2r,delta_s);
	}// 3000000,235000,22055000,723.15,413.15,647.1,0.345,3.47,0.00145,0,12100
	else if(val==0){
		printf("INVALID\n");
	}
	return 0;

}
