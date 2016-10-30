#include <stdio.h>
int main(){
    int low=2,hi=10,n,i,a;
    char s[100];
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d %s",&a,s);
      if(a<2||a>10)continue;
      if(s[0]=='h'&&a>low)low=a;
      else if(a<hi)hi=a;
    }
    if(low<hi)printf("%d\n",hi);
    else printf("Inconsistent\n");
}
