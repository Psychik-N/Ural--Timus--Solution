#include <iostream>
#include <math.h>
using namespace std;
int n,k;
bool f(int x)
{
    long long y=x*2-2,z=(long long)(sqrt((unsigned int)(y)));
    if(1+z*(z+1)/2==x)
        return true;
    return false;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        if(f(k))  cout<<1;
        else  cout<<0;
        cout<<endl;
    }
    return 0;
}

