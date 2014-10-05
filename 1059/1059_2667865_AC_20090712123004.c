#include <stdio.h>
int main(){
int n,i;
scanf("%d",&n);
printf("0\nX\n*\n");
for(i=1;i<n;i++)
printf("%d\n+\nX\n*\n",i);
printf("%d\n+\n",n);
}
