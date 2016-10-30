#include <stdio.h>
int main(){
    int n,i,j,on=0,f[2][35]={0},bv,a,b,t,m;
    char c;
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d",&m);
      for(j=1;j<=m;j++){
        bv=1e9;
        while(1){
          scanf("%d",&a);
          if(a==0)break;
          scanf("%d",&b);
          t=f[on][a]+b;
          if(t<bv)bv=t;
        }
        f[!on][j]=bv;
      }
      if(i!=n-1)do{c=getchar();}while(c!='*');
      on=!on;
    }
    bv=1e9;
    for(i=1;i<=m;i++)if(f[on][i]<bv)bv=f[on][i];
    printf("%d\n",bv);
}
