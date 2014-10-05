#include<iostream>
#include<cmath>
using namespace std;
int N;
const double eps=1e-9;
double a[3010],c[3010],x;
void solve()
{
for(int i=2;i<=N;i++)a[i]=2*(a[i-1]+c[i-1])-a[i-2]; 
x=2*(a[N]+c[N])-a[N-1];
}
int main()
{
scanf("%d",&N);
scanf("%lf%lf",&a[0],&a[N+1]);
for(int i=1;i<=N;i++)cin>>c[i];
double l=-2000.000,r=2000.00;
while(l-r<eps)
{
double mid=(l+r)/2.0;
a[1]=mid;
solve();
if(fabs(a[N+1]-x)<eps){printf("%.2lf\n",mid);break;} 
else if(a[N+1]-x<eps)r=mid;else l=mid;
}
return 0; 
}
