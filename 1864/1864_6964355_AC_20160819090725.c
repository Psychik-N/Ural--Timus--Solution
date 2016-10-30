#include <stdio.h>
int main(){
    int n,i,a[101],s=0;
    double b[101];
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",a+i);
    for(i=1;i<n;i++)if(a[i]!=a[0])goto nxt;
    for(i=0;i<n;i++)printf("%d ",100/n);
    return 0;
nxt:
    s=0;
    for(i=0;i<n;i++)s+=a[i];
    double v=(double)s/(n+1);
    for(i=0;i<n;i++)b[i]=a[i]<v?0:a[i]-v;
    double s2=0;
    for(i=0;i<n;i++)s2+=b[i];
    for(i=0;i<n;i++)printf("%d ",(int)(100*b[i]/s2+1e-6));
    return 0;
}
