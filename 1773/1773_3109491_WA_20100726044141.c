#include <stdio.h>
#include <stdlib.h>
int s[100010],bh[100010],fx[50010]={0},m[50010]={0},o[50010];
int cmp(int *a,int *b){
return s[*a]-s[*b];
}
int cmp2(int *a,int *b){
return -(s[*a]-s[*b]);
}
int main(){
int i,n,h,a,b,xl=0,t,c=1,lst;
for(i=0;i<50010;i++)bh[i*2]=bh[i*2+1]=i+1;
scanf("%d %d %d %d",&h,&n,&a,&b);
xl=a-b;
s[0]=a;
s[1]=h-b;
for(i=1;i<n;i++){
scanf("%d %d",&a,&b);
if(a-b!=xl){
puts("0");
return 0;
}
s[i*2]=a;
s[i*2+1]=h-b;
}
qsort(bh,n*2,4,cmp);
start:
lst=s[bh[0]];
o[0]=0;
for(i=1;i<n+n;i++)if(m[bh[i]]==0&&lst==s[bh[i]]+xl){
m[bh[i]]=1;
lst=s[bh[i]];
o[c++]=i;
}
if(c!=n)goto nxt;
for(i=0;i<n;i++){
if(bh[o[i]]%2==1)printf("-");
printf("%d ",bh[o[i]/2]);
}
return 0;
nxt:
c=1;
for(i=0;i<50010;i++)m[i]=0;
qsort(bh,n*2,4,cmp2);
goto start;
}


