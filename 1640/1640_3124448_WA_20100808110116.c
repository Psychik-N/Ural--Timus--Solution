#include <stdio.h>
#include <math.h>
int main(){
int n,i,t,bv=-1,x,y;
double l=0.0,r=4000.0,m;
scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%d%d",&x,&y);
t=(x-0)*(x-0)+(y-0)*(y-0);
if(t>bv)bv=t;
}

while(r-l>(1e-11)){
m=(r+l)/2.0;
if(m*m+(1e-12)<t)l=m-(1e-12);
else r=m+(1e-12);
}
printf("0 0 %.10lf\n",l);

//printf("0 0 %.9lf\n",sqrt((double)t));
}
