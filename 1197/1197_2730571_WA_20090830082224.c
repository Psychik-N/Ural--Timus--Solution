#include <stdio.h>
int m[8][8],c,bx[8]={-1,1,2,2,1,-1,-2,-2},by[8]={-2,-2,-1,1,2,2,1,-1};
void dfs(int x,int y){
int i;
if(m[x][y])return;
m[x][y]=1;
c++;
for(i=0;i<8;i++)
//if(x+bx[i]>=0&&x+bx[i]<8&&y+by[i]>=0&&y+by[i]<8)
dfs(x+bx[i],y+by[i]);
}
int main(){
char in[3];
int n,i,j;
scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%s",in);
c=0;
for(i=0;i<8;i++)for(j=0;j<8;j++)m[i][j]=0;
dfs(in[0]-'a',in[1]-'1');
printf("%d\n",c);
}
}
