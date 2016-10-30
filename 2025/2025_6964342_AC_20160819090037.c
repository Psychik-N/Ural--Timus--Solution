#include <stdio.h>
int main(){
  int t,n,k;
  scanf("%d",&t);
  while(t--){
    scanf("%d%d",&n,&k);
    printf("%d\n",((n/k+1)*(n-n/k-1)*(n%k)+(n/k)*(n-n/k)*(k-n%k))/2);
  }
  return 0;
}
