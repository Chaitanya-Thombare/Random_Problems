#include<stdio.h>
#include<math.h>

int main(){
	float W,B;
	
	scanf("%f %f",&W,&B);
	
	double c=fmod(W,5);
	
	if(c!=0 && B-W-0.5>=0) B=B-W-0.5;

	printf("%f",B);
	
	return 0;
}
/*
#include<stdio.h>
#include<math.h>

int main(){
	float W,B;
	
	scanf("%f %f",&W,&B);
	
	double c=fmod(W,5);
	
	if(c!=0 && B-W-0.5>=0) B=B-W-0.5;

	printf("%f",B);
	
	return 0;
}*/
