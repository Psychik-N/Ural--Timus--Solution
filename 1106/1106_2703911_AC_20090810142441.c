#include <stdio.h>
char con[101][101]={0},r[101]={0};
int n;
void dfs(int p){
     int i,suc=0;
     for(i=1;i<=n;i++){
       if(con[p][i]==0)continue;
       if(r[i]==0){
         suc=1;
         r[i]=3-r[p];
         dfs(p);
       }else if(r[i]!=r[p]){
         suc=1;
       }
     }
     if(suc==0){
       puts("0");
       exit(0);
     }
}   
int main(){
    int i,t;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
      while(1){
        scanf("%d",&t);
        if(t==0)break;
        con[i][t]=con[t][i]=1;
      }
    }
    for(i=1;i<=n;i++){
      if(r[i]==0){
        r[i]=1;
        dfs(i);
      }
    }
    t=0;
    for(i=1;i<=n;i++)
      if(r[i]==1)
        t++;
    printf("%d",t);
    for(i=1;i<=n;i++)
      if(r[i]==1)
        printf(" %d",i);
}
