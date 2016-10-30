#include <stdio.h>
int n,c[1010],fs1[1010][1010],fs2[1010][1010], cr[1010][1010]={0};
int go(int s,int e){
     int tmp=-1;
if(s>=n||e>=n)while(1);
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
    int i,j,k,ti,yl[4]={0};
    char in;
    scanf("%d\n",&n);
    for(i=0;i<n;i++){
      scanf("%c",&in);
      if(in=='R')c[i]=1;
      else if(in=='G')c[i]=2;
      else if(in=='B')c[i]=3;
else while(1);
yl[c[i]]=1;
      cr[i][(i+1)%n]=1;
    }
if(yl[1]+yl[2]+yl[3]!=3)goto my;
cr[n-1][n]=cr[n][1]=cr[0][1]=1;
    for(i=0;i<n;i++)
      if(go((i+1)%n,i)==1)goto yes;
my:
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
