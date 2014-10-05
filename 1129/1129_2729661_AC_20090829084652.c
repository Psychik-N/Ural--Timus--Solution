#include <stdio.h>
char c[101][101]={0},m[101][101]={0},o[101][101],x[2]={'Y','G'};
int n;
void go(int p,int s){
     int i;
     for(i=1;i<=n;i++){
       if(c[p][i]&(!m[p][i])){
         m[i][p]=m[p][i]=1;
         o[i][p]=x[s];
         o[p][i]=x[!s];
         go(i,s);
         break;
       }
     }
}
int main(){
    int i,j,k,in,s=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
      scanf("%d",&k);
      for(j=0;j<k;j++){
        scanf("%d",&in);
        c[in][i]=c[i][in]=1;
      }
    }
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        if(c[i][j]&(!m[i][j])){
          go(i,s);
          s=!s;
        }
    for(i=1;i<=n;i++){
      for(j=1;j<=n;j++)
        if(c[i][j])
          printf("%c ",o[i][j]);
      printf("\n");
    }
}
