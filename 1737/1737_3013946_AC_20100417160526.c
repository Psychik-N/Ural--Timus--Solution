#include <stdio.h>
char s[6][4]={"abc","acb","bac","bca","cab","cba"};
int main(){
    int n,i,j,k;
    scanf("%d",&n);
    if(n*6>100000)puts("TOO LONG");
    else if(n==1)puts("a\nb\nc");
    else for(i=0;i<6;i++){
      j=0;
      for(k=0;k<n;k++){
        putchar(s[i][j]);
        j++;
        if(j==3)j=0;
      }
      putchar('\n');
    }
}
