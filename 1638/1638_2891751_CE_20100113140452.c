#include<iostream>
using namespace std;
int a,b,c,d;
int main(){
    cin>>a>>b>>c>>d;
    if(c<d)cout<<(d-c-1)*(a+b+b)+b*2;
    else cout<<(c-d)*(a+b+b)+a;
    return 0;
}
