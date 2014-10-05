#include <stdio.h>
int main(){
    int n,s,i,j,t,f[10001]={0},k;
    scanf("%d%d",&n,&s);
    f[s]=1;
    for(i=s;i<=n;i++){
      t=i*100;
      for(j=101;j<=200;j++)
        if(t%j==0){
          k=t/j;
          if(f[k]>0&&f[k]+1>=f[i])
            f[i]=f[k]+1;
        }
    }
    t=0;
    for(i=s;i<=n;i++)
      if(f[i]>t)
        t=f[i];
    printf("%d",t);
}
