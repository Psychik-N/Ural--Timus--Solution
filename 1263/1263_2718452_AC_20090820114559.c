#include <stdio.h>
int main(){
int a,b,i,in,c[10001]={0};
scanf("%d%d",&a,&b);
for(i=0;i<b;i++){
scanf("%d",&in);
c[in]++;
}
for(i=1;i<=a;i++)
printf("%.2lf%%\n",(double)c[i]/(double)b*100);
}
