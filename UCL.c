#include<stdio.h>
#include<string.h>

struct Tb{
	char T[11];
	int Pt;
	int Gd;
};
struct Tb Table[4];

void Swap(int a, int b){
	struct Tb temp;
	
	temp=Table[a];
	Table[a]=Table[b];
	Table[b]=temp;
	
}

void Sort(){
	for(int i=0; i<4; i++){
		for(int j=0;j<4-i-1;j++){
			if(Table[j].Pt<Table[j+1].Pt) Swap(j,j+1);
			
			if(Table[j].Pt==Table[j+1].Pt){
				if(Table[j].Gd<Table[j+1].Gd) Swap(j,j+1);
			}
		}
	}
}

int SearchTeam(char key[11]){
	for(int i=0;i<4;i++){
		if(strcmp(key,Table[i].T)==0) return i;
	}
}

void Teams(char t1[11], char t2[11]){
	if(strlen(Table[0].T)==0 || strlen(Table[1].T)==0 || strlen(Table[2].T)==0 || strlen(Table[3].T)==0){
	
		if(strlen(Table[0].T)==0 && strlen(Table[1].T)==0){
			strcpy(Table[0].T,t1);
			strcpy(Table[1].T,t2);
		}
		else{
			if(strcmp(t1,Table[0].T)!=0){
				if(strcmp(t1,Table[1].T)!=0){
					if(strlen(Table[2].T)==0) strcpy(Table[2].T,t1);
					else{
						if(strcmp(t1,Table[2].T)!=0) strcpy(Table[3].T,t1);
					}
				}
			}
			if(strcmp(t2,Table[0].T)!=0){
				if(strcmp(t2,Table[1].T)!=0){
					if(strlen(Table[2].T)==0) strcpy(Table[2].T,t2);
					else{
						if(strcmp(t2,Table[2].T)!=0) strcpy(Table[3].T,t2);
					}
				}
			}
		}
	}	
}

void Input(){
	for(int i=0;i<12;i++){
		char t1[11],t2[11],g[4];
		int s1,s2;
		
		scanf("%s%d%s%d%s",t1,&s1,g,&s2,t2);
		
		Teams(t1,t2);
			
		int a=SearchTeam(t1);
		int b=SearchTeam(t2);
		
		if(s1>s2) Table[a].Pt+=3;
		if(s1<s2) Table[b].Pt+=3;
		if(s1==s2){
			Table[a].Pt+=1;
			Table[b].Pt+=1;
		}
		Table[a].Gd+=(s1-s2);
		Table[b].Gd+=(s2-s1);
	}
}

int main(){
	int Cases;
	scanf("%d",&Cases);
	
	while(Cases--){
		for(int i=0;i<4;i++){
			Table[i].Pt=Table[i].Gd=0;
			memset(Table[i].T,'\0',sizeof(Table[i].T));
		}
		Input();
		Sort();
		
		printf("%s %s",Table[0].T,Table[1].T);
	}
}
