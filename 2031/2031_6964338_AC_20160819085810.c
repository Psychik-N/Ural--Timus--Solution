#include <stdio.h>
int x[4]={16,6,68,88};
int main(){
  int n,i;
  scanf("%d",&n);
  if(n>4)printf("Glupenky Pierre\n");
  else for(i=0;i<n;i++)printf("%02d ",x[i]);
  return 0;
}
