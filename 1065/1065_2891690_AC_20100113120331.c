#include <stdio.h>
#include <math.h>
int mx[1010],my[1010],px[1010],py[1010];
double c[1010][1010],ans=2000000000;
double mmin(double a,double b){
if(a<b)return a;
return b;
}
double dist(int i,int j){
return sqrt((px[i]-px[j])*(px[i]-px[j])+(py[i]-py[j])*(py[i]-py[j]));
}
int cj(int a,int b,int c){
return (px[a]-px[c])*(py[b]-py[c])-(px[b]-px[c])*(py[a]-py[c]);
}
int cj2(int a,int b,int c){
return (px[a]-px[c])*(my[b]-py[c])-(mx[b]-px[c])*(py[a]-py[c]);
}
int check(int a,int b,int c,int x){
if((long long)cj2(a,x,c)*cj2(b,x,c)>0)return 0;
return 1;
}
int pd(int a,int b,int c,int x){
if(check(a,b,c,x)&&check(b,c,a,x)&&check(c,a,b,x))return 1;
return 0;
}
int main(){
int n,m,i,j,k;
scanf("%d%d",&n,&m);
for(i=0;i<n;i++){
scanf("%d%d",&px[i],&py[i]);
px[i+n]=px[i];
py[i+n]=py[i];
}
for(i=0;i<110;i++)for(j=0;j<110;j++)c[i][j]=1000000000;
for(i=0;i<m;i++)scanf("%d%d",&mx[i],&my[i]);
for(i=0;i<n;i++){
c[i][(i+1)%n]=dist(i,i+1);
for(j=i+2;j<i+n;j++){
if(cj(i,j,j-1)==0)goto nxt;
for(k=0;k<m;k++)if(pd(i,j,j-1,k))goto out;
c[i][j%n]=dist(i,j);
goto nxt;
nxt:;
}
out:;
}
for(k=0;k<n;k++)for(i=0;i<k;i++)for(j=k+1;j<n;j++)c[i][j]=mmin(c[i][j],c[i][k]+c[k][j]);
for(k=0;k<n;k++)
for(i=k+1;i<n;i++)
for(j=i+1;j<n;j++)
if(cj(i,j,k))
ans=mmin(ans,c[k][i]+c[i][j]+c[j][k]);
printf("%.2lf\n",ans);
}
