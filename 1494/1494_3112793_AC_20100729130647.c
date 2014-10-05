#include <stdio.h>
int in[1000000],stk[1000000];
int main(){
int i,n,sl=0,p=1;
scanf("%d",&n);
for(i=0;i<n;i++)scanf("%d",&in[i]);
for(i=0;i<n;i++){
if(sl>0&&in[i]==stk[sl-1])sl--;
else{
while(p<=n){
stk[sl++]=p++;
if(stk[sl-1]==in[i]){
sl--;
goto nxt;
}
}
printf("Cheater");
return 0;
}
nxt:;
}
printf("Not a proof");
}

