#include <stdio.h>
int main(){
    int n,s,i,j,t,f[10001]={0};
    scanf("%d%d",&n,&s);
    for(i=s;i<=n;i++){
      t=i*100;
      for(j=s;j<i;j++)
        if(f[j]+1>=f[i])
          if(i%j==0)
            f[i]=f[j]+1;
    }
    t=0;
    for(i=s;i<=n;i++)
      if(f[i]>t)
        t=f[i];
    printf("%d",t);
}
