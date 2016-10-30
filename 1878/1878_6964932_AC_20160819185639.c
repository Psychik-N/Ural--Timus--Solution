#include <stdio.h>
int main(){
    int bv=10000,m[4][4],t,i,j,tc;
    for(i=0;i<4;i++)for(j=0;j<4;j++)scanf("%d",&m[i][j]);
    
    for(tc=1;tc<=4;tc++){
        t=0;
        for(i=0;i<2;i++)for(j=2;j<4;j++)if(m[i][j]==tc)t++;
        for(i=2;i<4;i++)for(j=0;j<2;j++)if(m[i][j]==tc)t++;
        for(i=2;i<4;i++)for(j=2;j<4;j++)if(m[i][j]==tc)t+=2;
        if(t<bv)bv=t;
    }
    printf("%d\n",bv);
    return 0;
}
