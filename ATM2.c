#include<stdio.h>
#include<string.h>

void ATM(int A[], int B[], int N, int K){
	for(int i=0; i<N && K; i++){
		if(K>=A[i]){
			K=K-A[i];
			B[i]=1;
		}
		else B[i]=0;
	}
}

int main(){
	
	int Cases;
	scanf("%d",&Cases);
	
	while(Cases--){
		int N,K;
		scanf("%d %d",&N,&K);
		
		int A[N];
		int B[N];
		memset(B, 0, N*sizeof(int));
	
		for(int i=0;i<N;i++) scanf("%d",&A[i]);

		ATM(A,B,N,K);

		for(int i=0;i<N;i++) printf("%d ",B[i]);
		printf("\n");
	}
}
