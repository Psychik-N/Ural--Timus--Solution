#include <stdio.h>
#include <math.h>
int main(){
    int i,j,a,b,bi,flag;
    double bv=2,t;
    scanf("%d %d",&a,&b);
    if(a==1){puts("1");return 0;}
    for(i=b;i>=a;i--){
      flag=0;
      t=1;
      for(j=(int)(sqrt(b)+0.00000001);j>1;j--)if(i%j==0){
        flag=1;
        t+=j;
        t+=i/j;
      }
      if(flag==0){
        printf("%d\n",i);
        return 0;
      }
      t/=i;
      if(t<bv){
        bv=t;
        bi=i;
      }
    }
    printf("%d\n",bi);
}
