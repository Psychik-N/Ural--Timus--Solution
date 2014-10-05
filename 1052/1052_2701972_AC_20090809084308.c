#include <stdio.h>
int main(){
    int x[201],y[201],n,max=0,a,b,c,i,j,k,t;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
      scanf("%d %d",&x[i],&y[i]);
    for(i=1;i<n;i++){
      for(j=i+1;j<=n;j++){
        a=y[j]-y[i];
        b=x[j]-x[i];
        c=x[i]*a-y[i]*b;
        t=0;
        for(k=1;k<=n;k++){
          if(a*x[k]-b*y[k]==c)t++;
          if(t>max)max=t;
        }
      }
    }
    printf("%d",max);
}
