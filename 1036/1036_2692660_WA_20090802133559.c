#include <stdio.h>
int main(){
    char f[2][1001][100];
    int n,s,i,on=0;
    scanf("%d %d",&n,&s);
    if(s%2==1){
      printf("0");
      return 0;
    }
    if(s==0){
      printf("1");
      return 0;
    }
    s/=2;
}
