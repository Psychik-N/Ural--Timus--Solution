#include <stdio.h>
int n,c[1010],fs1[1010][1010],fs2[1010][1010],fs3[1010][1010],cr[1010][1010]={0};
void print(int s,int e,int flag){
     if((s+1)%n==e)return;
     print(fs1[s][e],fs2[s][e],0);
     print(fs2[s][e],fs3[s][e],0);
     if(flag==0)printf("%d %d\n",s+1,e+1);
}
int go(int s,int e){
     int tmp=-1,i=(e-1+n)%n;
     if(cr[s][e]!=0)return cr[s][e];
     while(1){
     if(c[s]+c[e]+c[i]==6&&c[s]*c[e]*c[i]==6&&go(s,i)==1&&go(i,e)==1){
       fs1[s][e]=s;
       fs2[s][e]=i;
       fs3[s][e]=e;
       tmp=1;
       goto out;
     }
     i--;
     if(i<0)i=n-1;
     if(s==i)break;
     }
     i=(s+1)%n;
     while(1){
     if(c[s]+c[e]+c[i]==6&&c[s]*c[e]*c[i]==6&&go(i,e)==1&&go(s,i)==1){
       fs1[s][e]=s;
       fs2[s][e]=i;
       fs3[s][e]=e;
       tmp=1;
       goto out;
     }
     i++;
     if(i==n)i=0;
     if(i==e)break;
     }
     out:
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
    printf("0");
    return 0;
    yes:
    printf("%d\n",n-3);
    j=(i+1)%n;
    print(j,i,1);
}
