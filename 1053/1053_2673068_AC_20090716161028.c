#include <stdio.h>
int main(){
int i,n,l1,l2,t;
scanf("%d",&n);
scanf("%d",&l1);
for(i=2;i<=n;i++){
scanf("%d",&l2);
while(l1!=l2){
if(l1<l2){
t=l1;
l1=l2;
l2=t;
}
l1%=l2;
if(l1==0)l1=l2;
}
}
printf("%d",l1);
}
