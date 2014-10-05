#include <stdio.h>
long long abs(long long a){
if(a>=0)return a;
return -a;
}
int main(){
long long a,b,t,i,n,bv=-1,bi;
scanf("%I64d %I64d",&n,&b);
for(i=1;i<n;i++){
a=b;
scanf("%I64d",&b);
t=abs(a-b);
if(t>bv){
bv=t;
bi=i;
}
}
printf("%I64d %I64d",bi,bi+1);
}
