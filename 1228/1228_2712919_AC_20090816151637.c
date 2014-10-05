#include <stdio.h>
int main(){
int n,s,t,i;
scanf("%d%d",&n,&s);
for(i=0;i<n;i++){
scanf("%d",&t);
printf("%d ",s/t-1);
s=t;
}
}
