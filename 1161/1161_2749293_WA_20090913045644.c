#include <stdio.h>
#include <math.h>
int main(){
int n,i,j,in[110],p[110],bi,bv;
double res=1;
scanf("%d",&n);
for(i=0;i<n;i++)scanf("%d",&in[i]);
for(i=0;i<n;i++){
bv=-1;
for(j=0;j<n;j++){
if(in[j]>bv){
bv=in[j];
bi=j;
}
}
p[i]=bv;
in[bi]=-1;
}
res=p[0];
for(i=1;i<n;i++)res=sqrt(res*p[i]);
printf("%.2lf",res);
}
