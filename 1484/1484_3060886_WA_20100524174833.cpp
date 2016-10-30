#include<iostream>
#include<math.h>
using namespace std;
int main(){
    double x,y,n,a;
    cin>>x>>y>>n;
    x+=0.05;
    y+=0.05;
    a=ceil(x*n-0.00001);
    cout<<int((a-n*y)/(y-1)+0.0001);
    system("pause");
}
