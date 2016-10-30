#include <stdio.h>
#include <string.h>
int main(){
    char in[100],tot[100100]={0};
    long long v[100100],f[100100]={0},bv=2000000000;
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
      f[k-1]+=v[i];
    for(i=k;i<n;i++)
      f[i]=f[i-1]+v[i]-v[i-k];
    for(i=k-1;i<n;i++){
      if(f[i]<1000000&&f[i]<bv){
        bv=(int)f[i];
        bi=i;
        m=1;
      }
    }
    if(m==0)
      puts("0");
    else
      printf("%d",bi-k+2);
}

