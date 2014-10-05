#include <stdio.h>
#include <stdlib.h>
int main(){
    int a[100010],i,n,mv;
    a[0]=0;
    a[1]=1;
    for(i=2;i<100005;i++){
      if((i&1)==0)a[i]=a[i>>1];
      else a[i]=a[(i-1)>>1]+a[((i-1)>>1)+1];
    }
    while(1){
      scanf("%d",&n);
      if(n==0)return 0;
      mv=-1;
      for(i=0;i<=n;i++)
        if(a[i]>mv)mv=a[i];
      printf("%d\n",mv);
    }
}
