#include <stdio.h>
int bh[101][150010],l[101]={0};
int main(){
    int n,i,j,a,b;
    scanf("%d",&n);
    for(i=0;i<n;i++){
scanf("%d%d",&a,&b);
      bh[b][l[b]]=a;
      l[b]++;
    }
    for(i=100;i>=0;i--){
      for(j=0;j<l[i];j++){
        printf("%d %d\n",bh[i][j],i);
      }
    }
}
