#include <stdio.h>
#include <math.h>
int main(){
    int n,i,l,ys[1000],yl=0,a;
    scanf("%d",&n);
    n*=2;
    l=(int)(sqrt((double)n))+1;
    for(i=1;i<=l;i++){
      if(n%i==0){
        ys[yl]=i;
        yl++;
      }
    }
    for(i=0;i<yl;i++)
      ys[yl*2-i-1]=n/ys[i];
    for(i=yl-1;i>=0;i--){
      a=n/ys[i]-ys[i]+1;
      if(a>0&&a%2==0){
        printf("%d %d",a/2,ys[i]);
        return 0;
      }
    }
}
