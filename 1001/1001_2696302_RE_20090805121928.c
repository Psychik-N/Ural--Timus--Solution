#include <stdio.h>
#include <math.h>
int main(){
    double a[100000000];
    long long n,i=0,j;
    while (scanf("%I64d",&n)!=EOF){
      a[i]=sqrt((double)(n));
      i++;
    }
    for (i--;i>=0;i--)
      printf ("%0.4lf\n",a[i]);
}
