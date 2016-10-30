#include <stdio.h>
int main(){
int n,p[1001],t,mark[1001]={0},c[1001]={0},cl=0,a,b,i;
scanf("%d",&n);
for(i=1;i<=n;i++)scanf("%d",&p[i]);
for(i=1;i<=n;i++){
if(mark[i])continue;
t=i;
do{
c[cl]++;
mark[t]=1;
t=p[i];
}while(t!=i);
cl++;
}
for(i=0;i<cl-1;i++){
a=c[i];
b=c[i+1];
if(b>a){
t=a;
a=b;
b=t;
}
while(a%b!=0){
t=a%b;
a=b;
b=t;
}
c[i+1]=c[i]/b*c[i+1];
}
printf("%d",c[cl-1]);
}
