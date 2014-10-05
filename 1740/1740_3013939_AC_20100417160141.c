#include <stdio.h>
int main(){
    int l,h,k;
    scanf("%d%d%d",&l,&k,&h);
    if(l%k==0)printf("%.8lf %.8lf",(double)l/k*h,(double)l/k*h);
    else printf("%.8lf %.8lf",(double)(l/k*h),(double)(l/k+1)*h);
}
