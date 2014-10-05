#include <stdio.h>
int main(){
int a,b,c,i,l=0;
scanf("%d%d",&a,&b);
for(i=0;i<b;i++){
scanf("%d",&c);
l+=c;
l-=a;
if(l<0)l=0;
}
printf("%d",l);
}
