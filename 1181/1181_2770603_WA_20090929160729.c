#include <stdio.h>
int n,c[10010],fs1[10010][10010],fs2[10010][10010];
char cr[10010][10010]={0};
char go(int s,int e){
     char tmp=-1;
     if(cr[s][e]!=0)return cr[s][e];
     if(c[s]+c[e]+c[(e-1+n)%n]==6&&c[s]*c[e]*c[(e-1+n)%n]==6&&go(s,(e-1+n)%n)==1){
       fs1[s][e]=s;
       fs2[s][e]=(e-1+n)%n;
       tmp=1;
     }else if(c[s]+c[e]+c[(s+1)%n]==6&&c[s]*c[e]*c[(s+1)%n]==6&&go((s+1)%n,e)==1){
       fs1[s][e]=(s+1)%n;
       fs2[s][e]=e;
       tmp=1;
     }
     cr[s][e]=tmp;
     return tmp;
}
int main(){
    int i,j,k,ti;
    char in;
    scanf("%d\n",&n);
    for(i=0;i<n;i++){
      scanf("%c",&in);
      if(in=='R')c[i]=1;
      else if(in=='G')c[i]=2;
      else c[i]=3;
      cr[i][(i+1)%n]=1;
    }
    for(i=0;i<=n;i++)
      if(go((i+1)%n,i)==1)goto yes;
    puts("0");
    return 0;
    yes:
    printf("%d\n",n-3);
    j=(i+1)%n;
    for(k=n-3;k>0;k--){
      printf("%d %d\n",fs1[j][i]+1,fs2[j][i]+1);
      ti=fs2[j][i];
      j=fs1[j][i];
      i=ti;
    }
}
