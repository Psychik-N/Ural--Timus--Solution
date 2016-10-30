#include <stdio.h>
long long a[100000],bv;
int cmp(const void *a,const void +b){
return *(long long*)a>*(long long*)b;
}
int main(){
int l=3,i;
scanf("%I64d%I64d%I64d",a,a+1,a+2);
while(1){
bv=1000000000000000001ll;
qsort(a,l,8,cmp);
for(i=1;i<l;i++)if(a[i]-a[i-1]<bv)bv=a[i]-a[i-1];
if(bv==0){
printf("%d\n,l-2);
return 0;
}
a[l++]=bv;
}
}
