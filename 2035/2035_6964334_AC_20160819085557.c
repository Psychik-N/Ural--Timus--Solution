#include <stdio.h>
int main(){
  int x,y,c;
  scanf("%d%d%d",&x,&y,&c);
  if(c<=x)printf("%d %d\n",c,0);
  else if(c<=y)printf("%d %d\n",0,c);
  else if(c<=x+y)printf("%d %d\n",x,c-x);
  else printf("Impossible\n");
  return 0;
}
