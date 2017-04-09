#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	float r = 8.314;
	float cp_average_h cp_average_s,tau;
	float b01,b02,b11,b12;
	float pi,pf,ti,tf,tc,pc,w,a,b,c,d;//inputs
	float partial_b01,partial_b02,partial_b11,partial_b12;
	float h1r,delta_hig,h2r,delta_h,s1r,delta_sig,s2r,delta_s;
	printf("ENTER INPUT: Pi,Pf,Pc,Ti,Tf,Tc,omega,A,B,C,D::\n");
	scanf("%f,%f,%f,%f,%f,%f,%f,%f,%f,%f",&pi,&pf,&pc,&ti,&tf,&tc,&w,&a,&b,&c,&d);
	printf("inputs are :%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n",pi,pf,pc,ti,tf,tc,w,a,b,c,d);
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
	delta_sig = (cp_average_s*log(t2/t1))-r*(log(pf/pi));
	delta_s = delta_sig + s2r - s1r;


}