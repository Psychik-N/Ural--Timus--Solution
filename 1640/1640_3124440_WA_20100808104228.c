#include <stdio.h>
int main(){
int n,i,t,bv=-1,x,y;
double l=0.0,r=4000.0,m;
scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%d%d",&x,&y);
t=(x-2000)*(x-2000)+(y-2000)*(y-2000);
if(t>bv)bv=t;
}
/*
while(r-l>(1e-11)){
m=(r+l)/2.0;
if(m*m<t)l=m;
else r=m;
}
printf("2000 2000 %.9lf\n",l);
*/
printf("2000 2000 %.9lf\n",sqrt((double)t));
}
