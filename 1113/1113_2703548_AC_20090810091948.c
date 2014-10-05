#include <stdio.h>
int main(){
    int n,m,a=1;
    double w=0,u=0;
    scanf("%d %d",&n,&m);
    while(1){
      w+=(double)m/(a*2-1);
      if(w>=n)break;
      u+=m;
      a++;
    }
    u+=m-(w-n)*(a*2-1);
    printf("%.0lf",u+0.499999999999999);
}
