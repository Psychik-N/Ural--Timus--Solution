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
n=1;
for(i=0;i<=10000;i++)
n*=f[i]+1;
if(n>5000000)system("pause");
printf("%d",n%10);
}

