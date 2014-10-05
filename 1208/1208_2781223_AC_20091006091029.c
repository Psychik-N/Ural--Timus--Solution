#include <stdio.h>
#include <string.h>
int n,rs=0,r[30][3],mark[100]={0},bv=-1;
char rm[100][25];
int max(int a,int b){
    if(a>b)return a;
    return b;
}
void go(int l,int h){
     if(l==n){
       bv=max(bv,h);
       return;
     }
     if(mark[r[l][0]]==0&&mark[r[l][1]]==0&&mark[r[l][2]]==0){
       mark[r[l][0]]=1;
       mark[r[l][1]]=1;
       mark[r[l][2]]=1;
       go(l+1,h+1);
       mark[r[l][0]]=0;
       mark[r[l][1]]=0;
       mark[r[l][2]]=0;
     }
     go(l+1,h);
}
int main(){
    int i,j,k;
    char in[25];
    scanf("%d",&n);
    for(i=0;i<n;i++){
      for(j=0;j<3;j++){
        scanf("%s",in);
        for(k=0;k<rs;k++){
          if(strcmp(in,rm[k])==0){
            r[i][j]=k;
            goto fin;
          }
        }
        strcpy(rm[rs],in);
        r[i][j]=rs;
        rs++;
        fin:;
      }
    }
    go(0,0);
    printf("%d",bv);
}
