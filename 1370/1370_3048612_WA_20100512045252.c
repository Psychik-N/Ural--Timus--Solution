#include <stdio.h>
int main(){
int n,k,i,s[1010];
scanf("%d%d",&n,&k);
for(i=0;i<n;i++)scanf("%d",&s[i]);
for(i=k;i<k+10;i++)printf("%d",s[(i-1)%n]);
}
