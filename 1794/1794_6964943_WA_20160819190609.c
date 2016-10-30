#include <stdio.h>
int v[100001]={0};
int main(){
int bv=0,bi,n,i,x;
scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%d",&x);
v[x]++;
}
for(i=1;i<=n;i++)if(v[i]>bv){
bv=v[i];
bi=i;
}
printf("%d\n",bi);
return 0;
}
