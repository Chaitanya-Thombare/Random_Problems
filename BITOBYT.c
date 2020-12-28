#include<stdio.h>

void BitGrow(long long int A[]){
	A[1]=A[0];
	A[0]=0;
}

void NibbleGrow(long long int A[]){
	A[2]=A[1];
	A[1]=0;
}

void ByteSplit(long long int A[]){
	A[0]=2*A[2];
	A[2]=0;
}

void CountPop(int A[], int N){
	for(int i=0,j=0; j<N; ++i,j++){
		if(i==2) BitGrow(A);
		if(i==10) NibbleGrow(A);
		if(i==26){
			ByteSplit(A);
			i=0;
		}
	}
}

int main(){
	int Cases;
	scanf("%d",&Cases);

	while(Cases--){
		long long int A[3]={1,0,0};
		int N;
		scanf("%d",&N);
		
		CountPop(A,N);
		printf("%d %d %d\n",A[0],A[1],A[2]);
		A[0]=A[1]=A[2]=0;
	}
	return 0;
}

