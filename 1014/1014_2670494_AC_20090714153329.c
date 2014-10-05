#include <stdio.h>
#include <math.h>
#include <string.h>
int main(){
    int n,i;
    char out[100]={0};
    scanf("%d",&n);
    if(n==0){
      printf("10");
      return 0;
    }
    if(n<10){
      printf("%d",n);
      return 0;
    }
    con:
      for(i=9;i>1;i--){
        if(n%i==0){
          out[strlen(out)]=i+'0';
          n/=i;
          if(n==1){
            for(i=strlen(out)-1;i>=0;i--)
              printf("%c",out[i]);
            return 0;
          }
          goto con;
        }
      }
    printf("-1");
}

