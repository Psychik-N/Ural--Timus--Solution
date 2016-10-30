#include <stdio.h>
char m[80000]={0},f=0;
int main(){
    int n,t,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d",&t);
      m[t+40000]=1;
    }
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d",&t);
      if(m[90000-t])f=1;
    }
    if(f==1)printf("YES");
    else printf("NO");
}
