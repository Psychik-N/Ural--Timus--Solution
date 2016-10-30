#include <stdio.h>
int main(){
  int n;
  double x,t,s;
  scanf("%d%lf%lf",&n,&t,&s);
  while(n--){
    scanf("%lf",&x);
    if(x>=s)printf("%.8lf\n",(t-(x-s))/2+x);
    else printf("%.8lf\n",(t-(s-x))/2+s);
  }
  return 0;
}
