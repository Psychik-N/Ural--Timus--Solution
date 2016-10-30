#include <stdio.h>
int main(){
    int a,b,c,j,i,tot=0;
    scanf("%d%d",&a,&b);
    while(scanf("%d%d",&a,&b)!=EOF){
      j=1;
      for(i=0;i<b;i++){
        scanf("%d%d",&a,&c);
        j*=c;
      }
      tot+=j;
    }
    printf("%d",tot);
}
