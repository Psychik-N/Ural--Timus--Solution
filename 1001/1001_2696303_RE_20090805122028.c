#include <stdio.h>
#include <math.h>
int main(){
    long long n,i=0,j;
    double a[100000000];
    while (scanf("%I64d",&n)!=EOF){
      a[i]=sqrt((double)(n));
      i++;
    }
    for (j=i-1;j>=0;j--)
      printf ("%0.4lf\n",a[j]);
}
