#include <stdio.h>
int main(){
  int s=0,a,n;
  scanf("%d",&n);
  while(n--){
    scanf("%d",&a);
    s+=a/2;
  }
  if(s%2==0)puts("Stannis");
  else puts("Daenerys");
  return 0;
}
