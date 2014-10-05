#include <stdio.h>
char o[100]={0};
int n,c[100][100],cl[100]={0};
int dfs(int p){
    int i,t;
    for(i=0;i<cl[p];i++){
      if(o[c[p][i]]==0){
        o[c[p][i]]=(o[p]=='0'?'1':'0');
        t=dfs(c[p][i]);
        if(t==-1)return -1;
      }
      else if(o[c[p][i]]==o[p])return -1;
    }
    return 0;
}
int main(){
    int i,t;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
      while(1){
        scanf("%d",&t);
        if(t==0)break;
        c[i][cl[i]]=t;
        cl[i]++;
        c[t][cl[t]]=i;
        cl[t]++;
      }
    }
    o[1]='0';
    t=dfs(1);
    if(t==-1){
      printf("-1");
      return 0;
    }
    for(i=1;i<=n;i++)
      printf("%c",o[i]);
}
