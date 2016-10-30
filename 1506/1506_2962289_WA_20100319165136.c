#include <stdio.h>
int main(){
    int n,i,j,r,k,p,b[1000];
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)if((n+i-1)/i==k)break;
    for(j=0;j<n;j++)scanf("%d",&b[j]);
    for(r=0;r<i;r++){
      p=r;
      printf("%4d",b[p]);
      p+=i;
      while(p<n){
        printf(" %4d",b[p]);
        p+=i;
      }
      printf("\n");
    }
}
