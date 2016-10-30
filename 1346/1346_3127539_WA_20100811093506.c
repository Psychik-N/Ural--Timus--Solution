#include <stdio.h>
int main(){
int a,b,i,l=2000000,c=0,d=0,t;
scanf("%d%d",&a,&b);
for(i=a;i<=b;i++){
scanf("%d",&t);
if(l==2000000)goto nxt;
if(d==0){
if(t>l)d=1;
if(t<l)d=-1;
}
if(d==1&&t<l){
c++;
d=0;
l=2000000;
continue;
}
if(d==-1&&t>l){
c++;
d=0;
l=2000000;
continue;
}
nxt:l=t;
}
printf("%d",c+1);
}
