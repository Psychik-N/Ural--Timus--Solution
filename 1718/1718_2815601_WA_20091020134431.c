#include <stdio.h>
int main(){
    int c1=0,c2=0,n,i,in;
    char a[100],b[10];
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%s %s",a,b);
      if(b[0]=='A')c2++;
      else if(b[0]=='C');
      else{
        scanf("%d",&in);
        if(in<6);
        else if(in==6)c2++;
        else{
          c1++;
          c2++;
        }
      }
    }
    printf("%d %d\n",c1,c2);
}
