#include <stdio.h>
int a[4001],b[4001],c[4001];
int main(){
int s=0,i,j,f,la,lb,lc;
scanf("%d",&la);
for(i=0;i<la;i++)scanf("%d",&a[i]);
scanf("%d",&lb);
for(i=0;i<lb;i++)scanf("%d",&b[i]);
scanf("%d",&lc);
for(i=0;i<lc;i++)scanf("%d",&c[i]);
for(i=0;i<la;i++){
f=0;
for(j=0;j<lb;j++)if(a[i]==b[j])f++;
for(j=0;j<lc;j++)if(a[i]==c[j])f++;
if(f==2)s++;
}
printf("%d\n",s);
return 0;
}
