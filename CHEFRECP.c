#include<stdio.h>
#include<stdlib.h>

int CompInt(const void *a1,const void *a2){
	const int *A1=a1;
	const int *A2=a2;
	return(*A1-*A2);
}

int TestRep(int Q[],int Limit){
	qsort(Q, Limit, sizeof(int), CompInt);
	for(int i=0;i<Limit-1;i++){
		if(Q[i]==Q[i+1]) return 0;
	}
	return 1;
}

int SplitArray(int A[], int B[], int C[], int N){
		int count=1,k=0,T=1;
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
			T=j;
		}
		
	}
	C[k++]=count;
	return T;
}

void Input(){
	int Limit;

	int N;	
	scanf("%d",&N);
	
	int RE[N];
	for(int i=0;i<N;i++) scanf("%d",&RE[i]);

	int IN[N], QT[N];
	
	Limit=SplitArray(RE,IN,QT,N);

	if(TestRep(IN,Limit)){
		if(TestRep(QT,Limit)) printf("YES");
		else printf("NO");
	}
	else printf("NO");
}

int main(){
	int Cases;
	scanf("%d",&Cases);
	
	while(Cases--){
		Input();
	}
	return 0;
}
