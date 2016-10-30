#include <stdio.h>
#include <stdlib.h>
int s[50010],bh[50010],fx[50010]={0};
int cmp(int *a,int *b){
return s[*a]-s[*b];
}
int main(){
int i,n,h,a,b,xl=0,t;
for(i=0;i<50010;i++)bh[i]=i+1;
scanf("%d %d %d %d",&h,&n,&a,&b);
if(a>b){
t=h-a;
a=h-b;
b=t;
fx[0]=-1;
}
xl=a-b;
s[0]=a;
for(i=1;i<n;i++){
scanf("%d %d",&a,&b);
if(a>b){
t=h-a;
a=h-b;
b=t;
fx[i]=-1;
}
if(a-b!=xl){
puts("0");
return 0;
}
s[i]=a;
}
qsort(bh,n,4,cmp);
for(i=1;i<n;i++)if(s[bh[i]]!=s[bh[i]-1]-xl){
puts("0");
return 0;
}
for(i=0;i<n;i++)printf("%d ",bh[i]*fx[bh[i]]);
}
