#include <stdio.h>
int main(){
    int l,n,i,in;
    scanf("%d%d",&l,&n);
    for(i=0;i<n;i++){
      scanf("%d",&in);
      l-=l%in;
      if(l<=0){
        puts("YES");
        return 0;
      }
    }
    puts("NO");
}
