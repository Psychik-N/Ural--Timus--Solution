#include <stdio.h>
int main(){
    int n,i,a,bv=0,now=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d",&a);
      if(a+now>0){
        now+=a;
        if(now>bv)bv=now;
      }else now=0;
    }
    printf("%d",bv);
}

