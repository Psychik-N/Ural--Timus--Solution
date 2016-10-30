#include <stdio.h>
int d[5][5];
int sx[4][5]={{1,3,2,4,5},{1,3,4,2,5},{1,4,3,2,5},{1,2,3,4,5}};
int main(){
  int i,j,bv=0x7fffffff,bi,c=0;
  for(i=0;i<5;i++)for(j=0;j<5;j++)scanf("%d",&d[i][j]);
  for(i=0;i<4;i++){
    c=0;
    for(j=1;j<5;j++)c+=d[sx[i][j-1]-1][sx[i][j]-1];
    if(c<bv){
      bv=c;
      bi=i;
    }
  }
  printf("%d\n",bv);
  for(i=0;i<5;i++)printf("%d ",sx[bi][i]);
  return 0;
}
