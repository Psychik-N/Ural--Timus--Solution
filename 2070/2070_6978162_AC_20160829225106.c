#include <stdio.h>
#include <math.h>
typedef long long i64;
int main(){
    i64 l,r,ans=0,m;
    int i,j,u,c,t;
    scanf("%lld%lld",&l,&r);
    t=(int)sqrt(r);
    for(i=2;i<=t;i++){
        u=(int)sqrt(i);
        for(j=2;j<=u;j++)if(i%j==0)goto nxt;
        m=i;
        c=1;
        while(m<=r){
            if(m>=l){
                if(c==2||c==4||c==6||c==10||c==12||c==16||c==18||c==22||c==28||c==30||c==36||c==40||c==42||c==46)ans--;
            }
            m*=i;
            c++;
        }
    nxt:;
    }
    ans+=r-l+1;
    printf("%lld\n",ans);
    return 0;
}
