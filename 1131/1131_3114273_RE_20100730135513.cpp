#include<iostream>
#include<cmath>
using namespace std;
int n,m;
int main()
{
if(m>=log(double(n-1.0))/log(2.0)+1.0-0.001)cout<<int(log(double(n-1.0))/log(2.0)+1.0-0.001+1.0);
else cout<<n-(int(pow(2.0,m)+0.001)-1)/m+1;
} 
