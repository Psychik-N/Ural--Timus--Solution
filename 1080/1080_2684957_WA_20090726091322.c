#include <stdio.h>
int main(){
    char c[100]={0};
    int con[100][100],cl[100]={0},q[2][100],ql[2]={1},on=0;
    int n,t,i,j;
    scanf("%d",&n);
    if(n==1)goto f;
    for(i=1;i<=n;i++){
      while(1){
        scanf("%d",&t);
        if(t==0)break;
        con[i][cl[i]]=t;
        cl[i]++;
        con[t][cl[t]]=i;
        cl[t]++;
      }
    }
    c[1]='0';
    q[0][0]=1;
    while(ql[on]>0){
      ql[!on]=0;
      for(i=0;i<ql[on];i++){
        for(j=0;j<cl[q[on][i]];j++){
          if(c[con[q[on][i]][j]]==0){
            c[con[q[on][i]][j]]=(c[q[on][i]]=='0'?'1':'0');
            q[!on][ql[!on]]=con[q[on][i]][j];
            ql[!on]++;
          }else if(c[con[q[on][i]][j]]==c[q[on][i]])goto f;
        }
      }
      on=!on;
    }
    for(i=1;i<=n;i++)
      printf("%c",c[i]);
    return 0;
    f:
    printf("-1");
}
