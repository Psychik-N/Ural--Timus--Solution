﻿#include<iostream>
#include<math.h>
using namespace std;
int main(){
    double x,y,n,a;
    cin>>x>>y>>n;
    if(y+0.0001>=x){cout<<0;return 0;}
    y+=0.05;
    a=int((x+0.05)*n-0.00001);
    cout<<ceil((a-n*y)/(y-1)+.000001);
    system("pause");
}
