#include <stdio.h>
char rm[10000][100];
int main(){
    int c1=0,c2=0,n,j,i,in,rs=0;
    char a[100],b[10];
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%s %s",a,b);
      for(j=0;j<rs;j++)if(strcmp(a,rm[j])==0)goto nxt;
      strcpy(rm[rs],a);
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
      nxt:;
    }
    printf("%d %d\n",c1,c2);
}
