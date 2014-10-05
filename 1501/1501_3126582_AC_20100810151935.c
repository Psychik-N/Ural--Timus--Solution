#include <stdio.h>
#include <string.h>
char f[1100][1100],x[1100][1100],va[1100],vb[1100];
char go(int a,int b){
     if(f[a][b]!=-2)return f[a][b];
     if(va[a]=='0'&&go(a-1,b)!=1&&f[a-1][b]!=2){
       x[a][b]=0;
       return f[a][b]=f[a-1][b]+1;
     }
     if(va[a]=='1'&&go(a-1,b)!=-1&&f[a-1][b]!=2){
       x[a][b]=0;
       return f[a][b]=f[a-1][b]-1;
     }
     if(vb[b]=='0'&&go(a,b-1)!=1&&f[a][b-1]!=2){
       x[a][b]=1;
       return f[a][b]=f[a][b-1]+1;
     }
     if(vb[b]=='1'&&go(a,b-1)!=-1&&f[a][b-1]!=2){
       x[a][b]=1;
       return f[a][b]=f[a][b-1]-1;
     }
     return f[a][b]=2;
}
int main(){
    int n,i,j,l=0;
    char o[2200];
    scanf("%d %s %s",&n,va+1,vb+1);
    j=i=n;
    memset(f,-2,1100*1100);
    f[0][0]=0;
    f[1][0]=va[1]=='0'?1:-1;
    f[0][1]=vb[1]=='0'?1:-1;
    x[1][0]=0;
    x[0][1]=1;
    if(go(n,n)==2){
      printf("Impossible\n");
      return 0;
    }
    while(i!=0||j!=0){
      o[l++]=x[i][j]+'1';
      if(x[i][j]==0)i--;
      else j--;
    }
    for(i=l-1;i>=0;i--)printf("%c",o[i]);
}
