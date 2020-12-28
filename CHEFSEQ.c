#include<stdio.h>
#include<stdlib.h>

long long int A[51][51]={0};

int CompInt(const void *a1,const void *a2){
	const int *A1=a1;
	const int *A2=a2;
	return(*A1-*A2);
}

void AssignArray(){
	for(int i=0;i<51;i++){
		for(int j=0;j<=i;j++){
			if(i==j || j==0) A[i][j]=1;
			else A[i][j]=A[i-1][j-1]+A[i-1][j];
		}
	}
}

void SplitArray(int A[], int B[], int C[], int N){
	int count=1,k=0,T=0;
	B[0]=A[0];
	for(int i=1,j=1;i<N;i++){
		
		if(A[i]==A[i-1]){
			count++;
			continue;
		}		
		else{
			C[k++]=count;
			count=1;
			B[j++]=A[i];
		}
		
	}
	C[k++]=count;
}

int Search(int E[],int Key){
	int i;
	for(i=0;E[i]!=Key;i++);
	return i;
}

long long int SubSeq(int n, int s, int K){
	long long int count=1;
	if(n+s==K) return count;
	else count=A[n][K-s];
	return count;
}

void Input(){
	int N, K;
	int n, s=0, t;
	scanf("%d",&N);
	scanf("%d",&K);

	int A[N],E[N],F[N];

	for(int i=0; i<N; i++) scanf("%d",&A[i]);
	
	qsort(A, N, sizeof(int), CompInt);

	SplitArray(A,E,F,N);

	t=Search(E,A[K-1]);
	n=F[t];
	
	for(int i=0; i<t;i++) s=s+F[i];

	printf("%lld\n",SubSeq(n,s,K));
}

int main(){
	int Cases;
	scanf("%d",&Cases);
	AssignArray();
	while(Cases--){
		Input();
	}
	return 0;
}

