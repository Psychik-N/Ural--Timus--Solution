#include <stdio.h>
int main(){
    int n,k,h=0,o=1;
    scanf("%d %d",&n,&k);
    if(n==1){
      puts("0");
      return 0;
    }
    while(o<k){
      o=o<<1;
      h++;
    }
    h+=(n-o-1)/k+1;
    printf("%d",h);
}
