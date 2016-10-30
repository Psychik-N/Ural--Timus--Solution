#include <stdio.h>
#include <math.h>
int main(){
    int zs[15001]={0,2},i,j,k,n,l=1,f;
    double t;
    for(i=2;i<=15000;i++){
      s:
      l++;l++;
      t=sqrt((double)l)+0.00001;
      f=0;
      for(j=1;j<i;j++){
        if(l%zs[j]==0){
          f=1;
          break;
        }
        if(zs[j]>t)break;
      }
      if(f==0)zs[i]=l;
      else goto s;
    }
    scanf("%d",&k);
    for(i=0;i<k;i++){
      scanf("%d",&n);
      printf("%d",zs[n]);
    }
}
