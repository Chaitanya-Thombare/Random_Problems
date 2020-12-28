#include<stdio.h>

int CheckWork(int A[],int N){
	int Sum=0,Dep;
	
	for(int i=0;i<N-1;i++) Sum=Sum+A[i];
	
	Sum=Sum*A[5];
	
	if(120<Sum) return 1;
	else return 0;
}

void Input(){
	int N=6;
	int A[6];
	
	//printf("Enter workload of all days");
	for(int i=0;i<N;i++) scanf("%d",&A[i]);
	
	if(CheckWork(A,N)) printf("Yes\n");
	else printf("No\n");
}

int main(){
	int Cases;
	//printf("Enter number of Cases:")
	scanf("%d",&Cases);
	
	while(Cases--){
		Input();
	}
	return 0;
}
