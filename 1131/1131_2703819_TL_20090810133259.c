#include <stdio.h>
int min(int a,int b){
    if(a<b)return a;
    return b;
}
int main(){
    int n,k,h=0,o=1;
    scanf("%d %d",&n,&k);
    if(n==1);
    else
    while(1){
      h++;
      o+=min(k,o);
      if(o>=n)break;
    }
    printf("%d",h);
}
