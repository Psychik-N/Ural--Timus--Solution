#include <stdio.h>
#include <string.h>
int main(){
    char in[100],tot[20000]={0};
    long long tf,lf=0,bv=2000000000;
    int v[100010];
    int n,k,i,tl,bi,m=0;
    scanf("%d %d",&n,&k);
    while(scanf("%s",in)!=EOF)
      strcat(tot,in);
    if(n<k){
      puts("0");
      return 0;
    }
    tl=strlen(tot);
    for(i=0;i<tl;i++){
      if(tot[i]=='*')
        v[i]=1000000;
      else
        v[i]=tot[i]-'0';
    }
    for(i=0;i<k;i++)
      lf+=v[i];
    if(lf<1000000&&lf<bv){
        bv=(int)lf;
        bi=0;
        m=1;
    }
    for(i=k;i<n;i++){
      tf=lf+v[i]-v[i-k];
      if(tf]<1000000&&tf<bv){
        bv=(int)tf;
        bi=i;
        m=1;
      }
      lf=tf;
    }
    if(m==0)
      puts("0");
    else
      printf("%d",bi-k+2);
}


