#include<iostream>
using namespace std;


int main(){
    long x,y;
    cin>>x>>y;
    if((x+y)%2==1)swap(x,y);
    cout<<x<<" "<<y;
    system("pause");
}
