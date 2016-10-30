#include <sdtio.h>
int abs(int a){
if(a>=0)return a;
return -a;
}
int main(){
int a,b,t,i,n,bv=-1,bi;
scanf("%d %d",&n,&b);
for(i=1;i<n;i++){
a=b;
scanf("%d",&b);
t=abs(a-b);
if(t>bv){
bv=t;
bi=i;
}
}
printf("%d %d",bi,bi+1);
}
