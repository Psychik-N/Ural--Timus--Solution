#include <stdio.h>
char c[1010][1010]={0},m[1010]={0};
int n;
void dfs(int p){
     int i;
     if(m[p]==1)return;
     m[p]=1;
     for(i=1;i<=n;i++)if(c[i][p]==1)dfs(i);
}
void ufs(int p){
     int i;
     if(m[p]==1)return;
     m[p]=1;
     for(i=1;i<=n;i++)if(c[i][p]==-1)ufs(i);
}
int main(){
    char in[20];
    int i,a,b;
    scanf("%d",&n);
    while(1){
      scanf("%s",in);
      if(in[0]=='B')break;
      a=atoi(in);
      scanf("%d",&b);
      c[a][b]=1;
      c[b][a]=-1;
    }
    while(scanf("%d",&a)!=EOF){
      dfs(a);
      m[a]=0;
      ufs(a);
    }
    a=-1;
    for(i=1;i<=n;i++)if(m[i]==0)printf("%d ",a=i);
    if(a==-1)printf("0");
}
