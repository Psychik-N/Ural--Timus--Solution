#include <stdio.h>
#include <math.h>
#pragma comment(linker,"/STACK:4000000")
double min(double a,double b){
if(a<b)return a;
return b;
}
int main(){
char x[1001][1001]={0};
double v[2][1001],g2=sqrt(2.0)*100;
int on=0,m,n,i,j,t1,t2,k;
scanf("%d%d%d",&n,&m,&k);
for(i=0;i<k;i++){
scanf("%d%d",&t1,&t2);
x[t1][t2]=1;
}
for(i=0;i<=m;i++)
v[0][i]=i*100;
for(i=1;i<=n;i++){
v[!on][0]=v[on][0]+100;
for(j=1;j<=m;j++){
v[!on][j]=min(v[on][j],v[!on][j-1])+100;
if(x[i][j])
v[!on][j]=min(v[!on][j],v[on][j-1]+g2);
}
on=!on;
}
printf("%.0lf",v[on][m]+0.4999999999999);
}
