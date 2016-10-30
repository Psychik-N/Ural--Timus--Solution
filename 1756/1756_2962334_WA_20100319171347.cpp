#include<iostream>
using namespace std;
int main(){
    int m,d1,d2,a,b,c,d,i;
    cin>>m>>d1>>d2;
    a=m*d1;
    b=a/d2;
    if(b*d2<=a)b++;
    while(a>b){
        cout<<b<<" ";
        d2--;
        a-=b;
    }
    if(a==0){
        for(i=1;i<=d2;i++)cout<<0<<" ";
    }else{
        cout<<a;
        for(i=1;i<d2;i++)cout<<0<<" ";
    }
    system("pause");
}