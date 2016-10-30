#include <stdio.h>
char map[830][830],mark[830][830]={0},mark2[830][830]={0};
int move[4][2]={-1,0,1,0,0,-1,0,1};
int q[2][1000000][2];
int main(){
int n,m,i,j,ql[2]={1},on=0,la,lb,time=0;
char in;
scanf("%d%d",&n,&m);
for(i=0;i<830;i++)map[0][i]='#';
for(i=1;i<=m;i++){
map[i][0]='#';
for(j=1;j<=n;j++){
do{
in=getchar();
}while(in!='.'&&in!='#');
map[i][j]=in;
}
map[i][n+1]='#';
}
for(i=1;i<=m;i++)for(j=1;j<=n;j++)if(map[i][j]=='.')goto out;
out:
q[0][0][0]=i;
q[0][0][1]=j;
while(ql[on]>0){
ql[!on]=0;
for(i=0;i<ql[on];i++){
la=q[on][i][0];
lb=q[on][i][1];
for(j=0;j<4;j++){
if(map[la+move[j][0]][lb+move[j][1]]=='.'&&mark[la+move[j][0]][lb+move[j][1]]==0){
q[!on][ql[!on]][0]=la+move[j][0];
q[!on][ql[!on]][1]=lb+move[j][1];
ql[!on]++;
mark[la+move[j][0]][lb+move[j][1]]=1;
}
}
}
on=!on;
}
ql[0]=1;
q[0][0][0]=la;
q[0][0][1]=lb;
on=0;
while(ql[on]>0){
ql[!on]=0;
time++;
for(i=0;i<ql[on];i++){
la=q[on][i][0];
lb=q[on][i][1];
for(j=0;j<4;j++){
if(map[la+move[j][0]][lb+move[j][1]]=='.'&&mark2[la+move[j][0]][lb+move[j][1]]==0){
q[!on][ql[!on]][0]=la+move[j][0];
q[!on][ql[!on]][1]=lb+move[j][1];
ql[!on]++;
mark2[la+move[j][0]][lb+move[j][1]]=1;
}
}
}
on=!on;
}
printf("%d",time-1);
}
