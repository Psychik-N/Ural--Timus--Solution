﻿#include <stdio.h>
int main(){
long i=1,xj,sj,p,q;
float tp,tq;
scanf("%f %f",&tp,&tq);
p=(long)(tp*100);
q=(long)(tq*100);
while(1){
xj=i*p;
sj=i*q;
if(xj/10000*10000+10000<sj){
printf("%d",(int)i);
return 0;
}
i++;
}
}
