#include <stdio.h>
int main(){
    double a,b,c;
    int d=0;
    scanf("%lf%lf%lf",&a,&b,&c);
    while(a>b){
      d++;
      a=(a*(100-c))/100;
    }
    printf("%d\n",d);
}

