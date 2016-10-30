#include <stdio.h>
int in[10001],n,m[10001],i,y[10000]={0};
void out(int s,int e){
     int i,j,bi,bv;
     printf("%d\n",e-s+1);
     for(i=s;i<=e;i++){
       bv=2000000000;
       for(j=s;j<=e;j++){
         if(in[j]<bv){
           bv=in[j];
           bi=j;
         }
       }
       printf("%d\n",in[bi]);
       in[bi]=2000000000;
     }
     exit(0);
}
int main(){
    m[0]=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
      scanf("%d",&in[i]);
      m[i]=(m[0]+in[i])%n;
      if(m[i]==0)out(1,i);
      if(y[m[i]]!=0)out(y[m[i]]+1,i);
      y[m[i]]=i;
    }
    puts("0");
}
