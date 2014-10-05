#include <stdio.h>
int c,bx[8]={-1,1,2,2,1,-1,-2,-2},by[8]={-2,-2,-1,1,2,2,1,-1};
void dfs(int x,int y){
int i;
for(i=0;i<8;i++)
if(x+bx[i]>=0&&x+bx[i]<8&&y+by[i]>=0&&y+by[i]<8)
c++;
}
int main(){
char in[3];
int n,i;
scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%s",in);
c=0;
dfs(in[0]-'a',in[1]-'1');
printf("%d\n",c);
}
}
