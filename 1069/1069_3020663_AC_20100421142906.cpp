#include<iostream>
using namespace std;
int a[7600],n=0,q[7600]={0},d[7600]={0},i,j,k,e[7600],ni,l[7600]={0},ll=0;

int main(){
    while(cin>>a[++n]);
    for(i=1;i<=n;i++)d[a[i]]++;
    for(i=1;i<=n;i++)if(d[i]==0)q[i]=1;
    for(ni=1;ni<=n-1;ni++){
        for(i=1;i<n;i++)if(q[i])break;
        e[ni]=i;
        q[i]=0;
        d[a[ni]]--;
        if(d[a[ni]]==0)q[a[ni]]=1;
    }
    for(i=1;i<=n;i++){
        memset(l,0,7600*4);
        ll=0;
        for(j=1;j<=n-1;j++){
            if(a[j]==i)l[++ll]=e[j];
            else if(e[j]==i)l[++ll]=a[j];
        }
        for(j=1;j<=ll;j++){
            for(k=0;k<=ll;k++){
                if(l[j]<l[k])swap(l[j],l[k]);
            }
        }
        cout<<i<<":";
        for(j=1;j<=ll;j++)cout<<" "<<l[j];
        cout<<endl;
    }
    system("pause");
}