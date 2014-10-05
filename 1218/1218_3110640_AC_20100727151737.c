#include <stdio.h>
char m[600]={0},c[600][600]={0},mz[600][50];
int n;
int az[600],bz[600],cz[600];
void dfs(int p){
int i;
m[p]=1;
for(i=0;i<n;i++)if(c[p][i]&&!m[i])dfs(i);
}
int main(){
int i,j;
scanf("%d",&n);
for(i=0;i<n;i++)scanf("%s %d %d %d",mz[i],&az[i],&bz[i],&cz[i]);
for(i=0;i<n;i++)for(j=0;j<n;j++)if((az[i]>az[j])+(bz[i]>bz[j])+(cz[i]>cz[j])>1)c[i][j]=1;
for(i=0;i<n;i++){
for(j=0;j<n;j++)m[j]=0;
dfs(i);
for(j=0;j<n;j++)if(m[j]==0)goto nxt;
printf("%s\n",mz[i]);
nxt:;
}
}

