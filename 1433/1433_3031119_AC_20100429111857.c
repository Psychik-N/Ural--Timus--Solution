#include <stdio.h>
int sx[12][4]={{0,1,2,3},{0,2,3,1},{0,3,1,2},{1,0,3,2},{1,3,2,0},{1,2,0,3},{2,0,1,3},{2,1,3,0},{2,3,0,1},{3,0,2,1},{3,2,1,0},{3,1,0,2}};
int main(){
    int i,m,n;
    char a[10],b[10];
    scanf("%s %s",a,b);
    for(m=0;m<12;m++)for(n=0;n<12;n++){
      for(i=0;i<4;i++)if(a[sx[m][i]]!=b[sx[n][i]])goto nxt;
      printf("equal\n");
      return 0;
      nxt:;
    }
    printf("different\n");
}
