#include <stdio.h>
int main(){
    int a,b,c,i;
    scanf("%d%d",&a,&b);
    for(i=0;i<10;i++){
      scanf("%d",&c);
      a+=c*20;
    }
    if(a>b)puts("Dirty debug :(");
    else puts("No chance.");
}
