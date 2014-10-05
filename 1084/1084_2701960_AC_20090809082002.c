#include <stdio.h>
#include <math.h>
int main(){
    double a,b,o,t;
    scanf("%lf %lf",&a,&b);
    o=b*b*3.1415926535897932384626433832795029;
    if(a/2>=b);
    else if(sqrt(a*a/2)>b){
      t=2*acos(a/2/b);
      o-=b*b*(t-sin(t))*2;
    }else o=a*a;
    printf("%.3lf",o);
}
