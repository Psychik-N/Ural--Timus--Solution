#include <stdio.h>
#include <string.h>
int main(){
char in[100],tot[10010]={0};
int n,i,j,k,bi,bv=2000000000,t;
scanf("%d %d",&n,&k);
while(scanf("%s",in)!=EOF)strcat(tot,in);
for(i=0;i<=n-k;i++){
t=0;
for(j=i;j<i+k;j++){
if(tot[j]=='*')goto nxt;
t+=tot[j]-48;
}
if(t<bv){
bv=t;
bi=i+1;
}
}
if(bv==2000000000)puts("0");
else printf("%d",bi);
}
