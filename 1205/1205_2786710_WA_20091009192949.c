#include <stdio.h>
#include <math.h>
#define eps 0
#pragma comment(linker,"/STACK:16777216")
int main(){
int n,i,j,k,p[210][210],a,b,c[210][210]={0},o[210],ol=0,bs=-1,be;
double x[210],y[210],dis[210][210],xp,yp,x2,y2,s1,s2,bv;
scanf("%lf%lf%d",&s1,&s2,&n);
for(i=1;i<=n;i++)scanf("%lf%lf",&x[i],&y[i]);
while(1){
scanf("%d%d",&a,&b);
if(a==0)break;
c[a][b]=c[b][a]=1;
}
scanf("%lf%lf%lf%lf",&xp,&yp,&x2,&y2);
for(i=1;i<=n;i++)for(j=1;j<=n;j++){if(c[i][j])dis[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))/s2;
else dis[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))/s1;}
for(i=1;i<=n;i++)for(j=1;j<=n;j++){
if(i==j){p[i][j]=0;dis[i][j]=1e100;}
else p[i][j]=i;
}
for(k=1;k<=n;k++)for(i=1;i<=n;i++)for(j=1;j<=n;j++)
if(dis[i][k]+dis[k][j]+eps<dis[i][j]){
dis[i][j]=dis[i][k]+dis[k][j];
p[i][j]=p[k][j];
}
bv=sqrt((xp-x2)*(xp-x2)+(yp-y2)*(yp-y2))/s1;
for(i=1;i<=n;i++)for(j=1;j<=n;j++){
if(i==j)continue;
if(sqrt((xp-x[i])*(xp-x[i])+(yp-y[i])*(yp-y[i]))+dis[i][j]+sqrt((x2-x[j])*(x2-x[j])+(y2-y[j])*(y2-y[j]))+eps<bv){
bv=sqrt((xp-x[i])*(xp-x[i])+(yp-y[i])*(yp-y[i]))+dis[i][j]+sqrt((x2-x[j])*(x2-x[j])+(y2-y[j])*(y2-y[j]));
bs=i;
be=j;
}
}
printf("%.6lf\n",bv);
if(bs==-1){
printf("0\n");
return 0;
}
k=be;
while(1){
o[ol]=k;
ol++;
if(bs==k)break;
k=p[bs][k];
}
printf("%d",ol);
for(i=ol-1;i>=0;i--)printf(" %d",o[i]);
}
