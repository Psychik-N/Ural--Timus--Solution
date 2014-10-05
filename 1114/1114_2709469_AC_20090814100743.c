#include <stdio.h>
int main(){
    int n,a,b,ai,bi,in,ia,ib;
    unsigned long long f[21][16][16],t;
    scanf("%d%d%d",&n,&a,&b);
    for(ai=0;ai<=a;ai++)
      for(bi=0;bi<=b;bi++)
        f[0][ai][bi]=1;
    for(in=1;in<=n;in++)
      for(ia=0;ia<=a;ia++)
        for(ib=0;ib<=b;ib++){
          t=0;
          for(ai=0;ai<=ia;ai++)
            for(bi=0;bi<=ib;bi++)
              t+=f[in-1][ia-ai][ib-bi];
          f[in][ia][ib]=t;
        }
    printf("%I64u",f[n][a][b]);
}
