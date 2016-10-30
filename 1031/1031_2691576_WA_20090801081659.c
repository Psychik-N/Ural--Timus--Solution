#include <stdio.h>
int min(int a,int b){
    if(a<b)return a;
    return b;
}
int main(){
    int l1,l2,l3,c1,c2,c3,n,i,j,s,e,dis[10010],f[10010],td;
    scanf("%d %d %d %d %d %d %d %d %d",&l1,&l2,&l3,&c1,&c2,&c3,&n,&s,&e);
    for(i=2;i<=n;i++)
      scanf("%d",&dis[i]);
    f[s]=0;
    for(i=s+1;i<=e;i++){
      f[i]=2000000000;
      for(j=s;j<i;j++){
        td=dis[i]-dis[j];
        if(td<=l1)f[i]=min(f[i],c1+f[j]);
        else if(td<=l2)f[i]=min(f[i],c2+f[j]);
        else if(td<=l3)f[i]=min(f[i],c3+f[j]);
      }
    }
    printf("%d",f[e]);
}
