#include<stdio.h>
#include<stdlib.h>
 long int i,j;

int CompInt(const void *a1,const void *a2){
	const int *A1=a1;
	const int *A2=a2;
	return(*A2-*A1);
}

void Input(){
	long int N,Sum=0,max=0,pos;

	scanf("%ld",&N);//Number of Cars
	
	long int Cars[N];
	for(i=0;i<N;i++) scanf("%ld",&Cars[i]); //Value of Each Car

	qsort(Cars, N, sizeof(Cars[i]), CompInt);
	
	for(i=0;i<N && Cars[i]>i;i++) Sum=Sum+Cars[i]-i;
	Sum=Sum%1000000007;
	printf("%ld\n",Sum);
}
int main(){
	int Cases;

	scanf("%d",&Cases); //Number of Cases
	
	while(Cases!=0){
		Input();
		Cases--;
	}
	return(0);
}
