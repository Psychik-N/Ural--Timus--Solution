#include <stdio.h>
int n,c[55][55]={0},sx[55][55],num[5000],nn=1;
void go(int p){
     int i;
     for(i=1;i<=n;i++){
       if(c[i][p]==1){
         c[i][p]=c[p][i]=0;
         num[sx[i][p]]=nn;
         nn++;
         go(i);
       }
     }
}
int main(){
    int i,m,a,b;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){
      scanf("%d%d",&a,&b);
      c[a][b]=c[b][a]=1;
      sx[a][b]=sx[b][a]=i;
    }
    go(1);
    puts("YES");
    for(i=1;i<=n;i++)printf("%d ",num[i]);
}
