#include <stdio.h>
const int MAX=201;
const int INF=0x7FFFFFFF;
struct T{
	int pos,fi,fj,gi,gj;
	char addition;
}G[MAX][MAX];
char S[MAX];
int N,F[MAX][MAX];
char opp(char a){
	switch(a){
		case '(': return ')';
		case ')': return '(';
		case '[': return ']';
	}
	return '[';
}
void peel(int i,int j){
	if (i+1<=N && j-1>=1){
		if ((S[i]=='(' && S[j]==')') || (S[i]=='[' && S[j]==']')){
		if (F[i+1][j-1]<F[i][j]){
				F[i][j]=F[i+1][j-1];
				G[i][j].fi=i+1;	G[i][j].fj=j-1;	G[i][j].pos=-1;
			}
		}
	}
}
void addhead(int i,int j){
	if (S[j]==')' || S[j]==']'){
		if (F[i][j-1]+1<F[i][j]){
			F[i][j]=F[i][j-1]+1;
			G[i][j].fi=i;
			G[i][j].fj=j-1;
			G[i][j].pos=1;
			G[i][j].addition=opp(S[j]);
		}
	}
}
void addtail(int i,int j){
	if (S[i]=='(' || S[i]=='['){
		if (F[i+1][j]+1<F[i][j]){
			F[i][j]=F[i+1][j]+1;
			G[i][j].fi=i+1;	G[i][j].fj=j;	G[i][j].pos=2;
			G[i][j].addition=opp(S[i]);
		}
	}
}
void split(int i,int j){
	int k;
	for(k=i;k<j;k++){
		if (F[i][k]+F[k+1][j]<F[i][j]){
			F[i][j]=F[i][k]+F[k+1][j];
			G[i][j].fi=i; G[i][j].fj=k;
			G[i][j].gi=k+1; G[i][j].gj=j;
			G[i][j].pos=-2;
		}
	}
}
void dynamic(){
	int i,j;
	for (i=N;i>=1;i--){
		for (j=i;j<=N;j++){
			F[i][j]=INF;
			split(i,j);
			peel(i,j);
			addtail(i,j);
			addhead(i,j);
		}
	}
}
void print(int i,int j){
	if (i>j) return;
	if (G[i][j].pos==-1){
		putchar(S[i]);
		print(i+1,j-1);
		putchar(S[j]);
	}
	else if (G[i][j].pos==-2){
		print(G[i][j].fi,G[i][j].fj);
		print(G[i][j].gi,G[i][j].gj);
	}
	else if (G[i][j].pos==1){
		putchar(G[i][j].addition);
		print(G[i][j].fi,G[i][j].fj);
		putchar(S[j]);
	}else{
		putchar(S[i]);
		print(G[i][j].fi,G[i][j].fj);
		putchar(G[i][j].addition);
	}
}
 
int main()
{
	scanf("%s",S+1);
	N=strlen(S+1);
	dynamic();
	print(1,N);
	return 0;
}
