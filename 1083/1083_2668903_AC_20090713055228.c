#include <stdio.h>
#include <string.h>
int main(){
unsigned long res=1;
int n,len,i;
char a[100];
scanf("%d %s",&n,a);
len=strlen(a);
for(i=n;i>0;i-=len)res*=i;
printf("%ld",res);
}
