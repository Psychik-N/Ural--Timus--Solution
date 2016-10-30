#include<iostream>
#include<cmath>
using namespace std;
int n,m;
int main()
{
if(m>=lg(double(n-1))/lg(2.0)+1-0.001)cout<<int(lg(double(n-1))/lg(2.0)+1-0.001+1);
else cout<<n-(int(pow(2.0,m)+0.001)-1)/m+1;
} 
