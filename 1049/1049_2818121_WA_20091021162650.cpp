#include <stdio.h>
int main(){
int n,i,j,f[10001]={0};
for(i=0;i<10;i++){
scanf("%d",&n);
s:
for(j=2;j<=n;j++){
if(n%j==0){
n/=j;
f[j]++;
goto s;
}
}
}
short n1=1;
for(i=0;i<=10000;i++)
n1*=f[i]+1;
printf("%d",(int)n1%10);
}

