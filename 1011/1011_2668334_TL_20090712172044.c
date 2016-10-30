#include <stdio.h>
#include <string.h>
int main(){
    long i=2,sj,xj,p=0,q=0;
    char in[10],find;
    double tp,tq;
    scanf("%lf %lf",&tp,&tq);
    p=(long)(tp*100);
    q=(long)(tq*100);
    while(1){
      xj=i*p;
      sj=i*q;
      if(sj-xj/10000*10000>10000){
        printf("%ld",i);
        return 0;
      }
      i++;
    }
}
