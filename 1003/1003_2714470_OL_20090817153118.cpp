#include<iostream>
using namespace std;
int main(){
int a[20002][2],s,n,i,t,x,y,tc,fx,fy,j,cx,cy,sc;
char c[10];
while(1){
cin>>s;
if(s==-1)break;
cin>>n;
a[0][0]=0;
a[0][1]=1;
t=1;
sc=1;
for(i=1;i<=n/2;i+=1){
cin>>x>>y>>c;
if(c[0]=='o')tc=0;
else tc=1;
fx=0;
fy=0;
for(j=0;j<t;j++){
if(a[j][0]==x-1){
fx=1;
cx=a[j][1];
}else if(a[j][0]==y){
fy=1;
cy=a[j][1];
}else{
}
}
if(fx==1&&fy==1){
if(cx/2==cy/2){
if((cx-cy)*(cx-cy)==tc){}
else{
cout<<"i"<<endl;
goto out;
}
}else{
if(tc==0){}
else{
if(cx%2==0)cx++;
else cx--;
for(j=0;j<t;j++){
if(a[j][1]==cy)a[j][1]=cx;
}
}
}
}else if(fx==1){
if(tc==0){}
else{
if(cx%2==0)cx++;
else cx--;
}
a[t][0]=y;
a[t][1]=cx;
t++;
}else if(fy==1){
if(tc==0){}
else{
if(cy%2==0)cy++;
else cy--;
}
a[t][0]=x-1;
a[t][1]=cy;
t++;
}else{
if(sc%2==1)sc++;
a[t][0]=x-1;
a[t][1]=sc;
t++;
if(tc==1)sc++;
a[t][0]=y;
a[t][1]=sc;
t++;
sc++;
}
}
cout<<n<<endl;
out://
}
}
