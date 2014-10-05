#include <stdio.h>
int main(){
    char o[1000001];
    int n,i,p,ta,tb;
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d %d",&ta,&tb);
      o[i]=(char)ta+(char)tb;
      p=i;
      while(o[p]>9){
        o[p]-=10;
        p--;
        o[p]++;
      }
    }
    for(i=0;i<n;i++)
      printf("%c",o[i]+48);
}

