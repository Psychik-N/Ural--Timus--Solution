#include <stdio.h>
int main(){
int n,k,a1=0,a2=0,i,a;
scanf("%d%d",&n,&k);
for(i=0;i<n;i++){
scanf("%d",&a);
if(a<k)a2+=k-a;
else a1+=a-k;
}
printf("%d %d",a1,a2);
return 0;
}