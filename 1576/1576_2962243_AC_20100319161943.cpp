#include<iostream>
using namespace std;
int main(){
    int n1,c1,n2,t0,c2,c3,n,i,a,b,t=0;
    char c;
    cin>>n1>>c1>>n2>>t0>>c2>>c3;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a>>c>>b;
        t+=(a+1);
        if((b<=6&&a==0)||b==0)t--;
    }
    cout<<"Basic:     "<<n1+t*c1<<endl;
    cout<<"Combined:  "<<n2+max(t-t0,0)*c2<<endl;
    cout<<"Unlimited: "<<c3<<endl;
    system("pause");
}
