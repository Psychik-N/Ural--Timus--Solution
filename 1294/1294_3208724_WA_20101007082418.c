#include <stdio.h>
int main(){
    double ad,ac,bd,bc,l,r;
    scanf("%lf%lf%lf%lf",&ad,&ac,&bd,&bc);
    ad*=1000;
    ac*=1000;
    bd*=1000;
    bc*=1000;
    l=(ad*ad+ac*ac)*bd*bc-(bd*bd+bc*bc)*ad*ac;
    r=bd*bc-ad*ac;
    if(abs(r)<1e-6||l/r<0)printf("Impossible.");
    else printf("Distance is %.0lf km.",sqrt(l/r));
}
