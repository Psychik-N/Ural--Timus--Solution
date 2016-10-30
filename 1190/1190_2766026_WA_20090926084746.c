#include <stdio.h>
int main(){
    int n,i,y,s[10010]={0},tot=0,max=0,lst;
    char in[20];
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%s%d",in,&y);
      if(y==1)scanf("%d",&s[i]);
    }
    if(s[0]=0){
      max=11111;
      goto nxt;
    }
    for(i=0;i<n;i++){
      if(s[i]!=0)lst=s[i];
      max+=lst;
    }
nxt:
    lst=1;
    for(i=n-1;i>=0;i--){
      if(s[i]!=0)lst=s[i];
      tot+=lst;
    }
    if(tot<=10000&&max>=10000)puts("YES");
    else puts("NO");
}
