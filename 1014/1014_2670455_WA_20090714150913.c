#include <stdio.h>
#include <math.h>
#include <string.h>
int main(){
    int n,i;
    char out[100]={0};
    scanf("%d",&n);
    if(n<10){
      printf("%d",n);
      return 0;
    }
    con:
      for(i=2;i<=n;i++){
        if(i>9){
          printf("-1");
          return 0;
        }
        if(n%i==0){
          out[strlen(out)]=i+'0';
          n/=i;
          if(n==1){
            printf("%s",out);
            return 0;
          }
          goto con;
        }
      }
}
