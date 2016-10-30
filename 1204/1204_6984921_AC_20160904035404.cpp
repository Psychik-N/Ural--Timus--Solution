#include <stdio.h>
void swap(int &a,int &b){
a^=b^=a^=b;
}
void exGcd(int a,int b,int& x,int& y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return;
    }
    exGcd(b,a%b,x,y);
    int t = x;
    x = y;
    y = t - a / b * y;
}
bool isprime(int x)
{
    for(int i = 2 ; i * i < x ; i++)
    {
        if(x % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int T,n,p,q,x,y ;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d",&n) ;
        for(int i = 2 ; i * i < n  ; i++)
        {
            if( (n%i == 0) && isprime(i) && isprime(n/i) )
            {
                p = i ;
                q = n/i ;
                break ;
            }
        }
        exGcd(p,q,x,y) ;
        int ans1 = p*x < 0 ? p*x+n : p*x ;
        exGcd(q,p,x,y) ;
        int ans2 = q*x < 0 ? q*x+n : q*x ;
        if(ans1 > ans2)
            swap(ans1,ans2) ;
        printf("0 1 %d %d\n",ans1,ans2) ;
    }
    return 0 ;
}
