#include<stdio.h>
#include<string.h>

int Power(int x,int y){
	int result=1;
	for(int i=0;i<y;i++) result=result*x;
	return result;
}

void Conv(int A[],int d,int b){
	if(d>=0){
		if(A[d]<b) A[d]++;
		else{
			A[d]=0;
			Conv(A,d-1,b);
		}
	}
}

int CheckPallindrome(int A[],int N){
	for(int i=0;i<N/2;i++){
		if(A[i]!=A[N-1-i]) return 0;
	}
	return 1;
}

void Input(){
	int N;
	scanf("%d",&N);
	
	int fav=1;
	int ev=Power(10,N);
	
	int A[N];
	memset(A, 0, N*sizeof(int));
	
	for(int i=0;i<ev;i++){
		Conv(A,N-1,9);
		if(CheckPallindrome(A,N)) fav++;
	}
	
	while(fav!=1){
		fav=fav/10;
		ev=ev/10;
	}
	printf("%d %d",fav,ev);
}

void main(){
	int Cases;
	scanf("%d",&Cases);
	
	while(Cases--){
		Input();
	}
}
