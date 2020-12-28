#include<stdio.h>
#include<stdlib.h>

int CompInt(const void *a1,const void *a2){
	const int *A1=a1;
	const int *A2=a2;
	return(*A1-*A2);
}

int CountAhead(int A[],int N, int P){
	int count=0;
	for(int i=P; i<N-1; i++){
		if(A[i+1]-A[i]<=2) count++;
		else return count;
	}
	return count;
}

int CountBehind(int A[],int N, int P){
	int count=0;
	for(int i=P; i>0; i--){
		if(A[i]-A[i-1]<=2) count++;
		else return count;
	}
	return count;
}

int CountInfected(int A[], int N, int P){
	int count;
	if(P==0) count=CountAhead(A,N,P);
	if(P==N-1) count=CountBehind(A,N,P);
	else{
		count=CountAhead(A,N,P);
		count+=CountBehind(A,N,P);
	}
	return count+1;
}

void Input(){
	int N;
	scanf("%d",&N);
	
	int A[N];
	for(int i=0; i<N; i++) scanf("%d",&A[i]);
	
	int B[N];
	
	for(int i=0; i<N; i++) {
		B[i]=CountInfected(A,N,i);
	}
	
	qsort(B, N, sizeof(int), CompInt);	
	
	printf("%d %d",B[0],B[N-1]);

}

int main(){
	int Cases;
	scanf("%d",&Cases);
	
	while(Cases--){
		Input();
	}
	return 0;
}
