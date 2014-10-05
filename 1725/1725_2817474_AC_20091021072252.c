#include <stdio.h>
int main(){
int n,k;
scanf("%d%d",&n,&k);
if(n==2){puts("0");return 0;}
if(k>n/2)k=n-k+1;
printf("%d",n-k-2);
}
