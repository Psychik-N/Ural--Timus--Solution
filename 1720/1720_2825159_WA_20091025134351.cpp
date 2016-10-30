#include<iostream>
using namespace std;
unsigned long long x,y,l,r;

unsigned long long go(unsigned long long d){
    if(d<=y){
        if(d<=x)return 0;
        return d+1-x;
    }
    if(x!=y){
        unsigned long long k=(y-1)/(y-x);
        if(x*k<=d)return go(x*k-1)+d+1-x*k;
    }
    unsigned long long a=d/x;
    if(a*y!=d){
        if(a*y>=d)return go(a*y)-(a*y-d);
        return go(a*y);
    }
    return a*(a+1)/2*(y-x)+a;
}


int main(){
    cin>>x>>y>>l>>r;
    cout<<go(r)-go(l-1);
    system("pause");
}
