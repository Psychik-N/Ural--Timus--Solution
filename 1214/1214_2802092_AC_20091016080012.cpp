#include<iostream>
using namespace std;


int main(){
    long x,y;
    cin>>x>>y;
    if(x<=0||y<=0){
        cout<<x<<" "<<y;
        return 0;
    }
    if((x+y)%2==1)swap(x,y);
    cout<<x<<" "<<y;
    system("pause");
}
