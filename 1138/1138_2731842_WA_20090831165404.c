#include <stdio.h>
int main(){
    int n,s,i,j,t,f[10001]={0};
    scanf("%d%d",&n,&s);
    f[s]=1;
    for(i=s;i<=n;i++){
      t=i*100;
      for(j=s;j<i;j++)
        if(f[j]+1>=f[i])
          if(t%j==0)
            f[i]=f[j]+1;
    }
    t=0;
    for(i=s;i<=n;i++)
      if(f[i]>t)
        t=f[i];
    printf("%d",t);
}
