#include<iostream>
#include<math.h>
using namespace std;
double dist(double x1,double y1,double x2,double y2){
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}
int main(){
    int n,i,j,y[51];
    double t1,t2,dt,x1,y1,x2,y2,r,pt,px,py,d,rd[51],tx1[51],ty1[51],tx2[51],ty2[51],pi=3.1415926535897932384,tpx,tpy;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>tx1[i]>>ty1[i]>>tx2[i]>>ty2[i];
        y[i]=i;
    }
    cin>>tpx>>tpy;
    for(i=1;i<=n;i++){
        x1=tx1[i];
        x2=tx2[i];
        y1=ty1[i];
        y2=ty2[i];
        px=tpx;
        py=tpy;
        r=dist(x1,y1,x2,y2);
        d=dist(x1,y1,px,py);
        t1=atan2(y2-y1,x2-x1);
        t2=pi/4;
        dt=t2-t1;
        x2=x1+r*sin(t2);
        y2=y1+r*cos(t2);
        pt=atan2(py-y1,px-x1);
        px=x1+d*sin(pt+dt);
        py=y1+d*cos(pt+dt);
        if(px<=x1&&py<=y1)
            rd[i]=dist(px,py,x1,y1);
        else if(px<=x1&&py<=y2)
            rd[i]=fabs(px-x1);
        else if(px<=x1)
            rd[i]=dist(px,py,x1,y2);
        else if(px<=x2&&py>y2)
            rd[i]=fabs(py-y2);
        else if(py>y2)
            rd[i]=dist(px,py,x2,y2);
        else if(px<=x2&&py<=y1)
            rd[i]=fabs(py-y1);
        else if(py<=y1)
            rd[i]=dist(px,py,x2,y1);
        else if(px>=x2)
            rd[i]=fabs(px-x2);
        else 
            rd[i]=0;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(rd[i]<rd[j]){swap(rd[i],rd[j]);swap(y[i],y[j]);}
    for(i=1;i<=n;i++)
        cout<<y[i]<<" ";
    system("pause");
}
