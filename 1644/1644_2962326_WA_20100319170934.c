#include <stdio.h>
int main(){
    int low=0,hi=999,n,i,a;
    char s[100];
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d %s",&a,s);
      if(s[0]=='h'&&a>low)low=a;
      else if(a<hi)hi=a;
    }
    if(low<hi)printf("%d\n",hi);
    else printf("Inconsistent\n");
}
