#include <stdio.h>
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<n;i++)printf("(");
    for(i=1;i<=n;i++){
      printf("sin(1");
      for(j=2;j<=i;j++)printf("%csin(%d",(j&1)==0?'-':'+',j);
      for(j=1;j<=i;j++)printf(")");
      printf("+%d",n-i+1);
      if(i!=n)printf(")");
    }
}
