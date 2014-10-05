#include <stdio.h>
#include <math.h>
double a[100000000];
double x;
 
int main(){
    long long n,i=0,j;
    while (scanf("%I64d",&n)!=EOF){
      a[i]=sqrt((double)(n));
      i++;
    }
    for (j=i-1;j>=0;j--){
      x=a[j]+0.00005;
      printf ("%0.4lf\n",a[j]);
    }
}
