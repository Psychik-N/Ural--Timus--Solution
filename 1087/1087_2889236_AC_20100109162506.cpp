#include <iostream>
using namespace std;
int n,m,a[50];
bool f[10001];
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        f[i]=false;
    f[0]=true;
    for(int i=1;i<=n;i++)
        for(int j=0;j<m;j++)
            if(i>=a[j]&&!f[i-a[j]])
            {
                f[i]=true;
                break;
            }
    cout<<2-f[n];
    return 0;
}

