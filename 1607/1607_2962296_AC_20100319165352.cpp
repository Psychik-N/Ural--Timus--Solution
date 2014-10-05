#include<iostream>
using namespace std;
int main(){
    int a,b,c,d,e;
    cin>>a>>b>>c>>d;
    if(a>=c){
        cout<<a;
        return 0;
    }
    e=(c-a)/(b+d);
    a+=e*b;
    c-=e*d;
    if(a+b<c)cout<<a+b;
    else cout<<c;
    system("pause");
}