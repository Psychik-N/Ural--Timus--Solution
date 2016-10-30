#include <stdio.h>
int main(){
    double h,t,v,x;
    scanf("%lf%lf%lf%lf",&h,&t,&v,&x);
    printf("%.8lf %.8lf\n",h<=t*x?0:(h-x*t)/(v-x),h>x*t?t:h/x);
    return 0;
}
