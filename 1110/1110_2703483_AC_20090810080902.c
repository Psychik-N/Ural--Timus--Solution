#include <stdio.h>
int main(){
    int i,x,ys,n,m,y,f=0;
    scanf("%d%d%d",&n,&m,&y);
    for(x=0;x<m;x++){
      ys=1;
      for(i=0;i<n;i++)
        ys=ys*x%m;
      if(ys==y){
        printf("%d ",x);
        f=1;
      }
    }
    if(f==0)puts("-1");
}
