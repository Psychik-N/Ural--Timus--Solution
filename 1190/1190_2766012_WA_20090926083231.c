#include <stdio.h>
int main(){
    int n,i,y,s[10010]={0},lst=1,tot=0;
    char in[20];
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%s%d",in,&y);
      if(y==1)scanf("%d",&s[i]);
    }
    for(i=n-1;i>=0;i--){
      if(s[i]!=0)lst=s[i];
      tot+=lst;
    }
    if(tot>10000)puts("NO");
    else puts("YES");
}
