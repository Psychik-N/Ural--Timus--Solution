#include <stdio.h>
int main(){
int i=1;
double p,q,xj,sj;
scanf("%d %d",&p,&q);
p/=100;
q/=100;
while(1){
xj=p*i;
sj=q*i;
if((int)xj<(int)sj&&(int)xj+1<sj){
printf("%d",(int)xj+1);
return 0;
}
i++;
}
}
