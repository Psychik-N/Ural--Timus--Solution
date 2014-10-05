#include<iostream>
#include<math.h>
using namespace std;
int main(){
    double x,y,n;
    int a;
    cin>>x>>y>>n;
    if(y+0.0001>=x){cout<<0;return 0;}
    y+=0.05;
    a=x*n;
    if(x<9.99999){
        x+=0.05;
        a=x*n-0.00001;
    }
    cout<<int((a-n*y)/(y-1)+1.00001);
    system("pause");
}
