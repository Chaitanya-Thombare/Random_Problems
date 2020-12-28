#include<stdio.h>

int i,itr=0;
int Result(int R[], int S[]){
	for(i=0;i<100;i++){
		itr++;
		if(S[i]==1){
			if(R[i]==0) return(0);
		}
	}
	return(1);
}

void Input(){
	int t;	
	
	int TRN;
	scanf("%d",&TRN);
	int TR[100]={0};
	for(i=0;i<TRN;i++){
		itr++;
		scanf("%d",&t);
		TR[t]=1;
	}

	int DRN;
	scanf("%d",&DRN);
	int DR[100]={0};
	for(i=0;i<DRN;i++){
		itr++;
		scanf("%d",&t);
		DR[t]=1;
	}
	
	int TSN;
	scanf("%d",&TSN);
	int TS[100]={0};
	for(i=0;i<TSN;i++){
		itr++;
		scanf("%d",&t);
		TS[t]=1;
	}

	int DSN;
	scanf("%d",&DSN);
	int DS[100]={0};
	for(i=0;i<DSN;i++){
		itr++
		scanf("%d",&t);
		DS[t]=1;
	}
	
	int TResult = Result(TR,TS);
	if(TResult){
		int DResult = Result(DR,DS);
		if(DResult)	printf("yes");
		else printf("no");
	}
	else printf("no");
	printf("%d",itr)
	printf("\n");
}
int main(){
	int Cases;
	scanf("%d",&Cases);
	
	while(Cases!=0){
		Input();
		Cases--;
	}
	return(0);
}
