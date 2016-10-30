#include<iostream>
using namespace std;
int main(){
    int m,d1,d2,a,b,c,d,i;
    cin>>m>>d1>>d2;
    a=m*d1;
    b=a/d2;
    if(b*d2!=a)b++;
    c=a/b;
    for(i=1;i<=c;i++)cout<<b<<" ";
    a-=(b*c);
    if(a!=0){
        cout<<a;
        for(i=i+1;i<=d2;i++)cout<<0<<" ";
    }else{
        for(i=i;i<=d2;i++)cout<<0<<" ";
    }
    system("pause");
}