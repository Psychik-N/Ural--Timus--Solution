#include<iostream>
using namespace std;
int main(){
int a[20002][2],e[50000][2],s,n,i,t,x,y,tc,fx,fy,j,cx,cy,sc,te,next,l[15001];
char c[10];
for(i=0;i<=15000;i++)e[i][0]=i;
while(1){
cin>>s;
if(s==-1)break;
for(i=0;i<=15000;i++){
e[i][1]=-1;
l[i]=i;
}
te=15001;
cin>>n;
a[0][0]=0;
a[0][1]=1;
t=1;
sc=1;

for(i=1;i<=n;i+=1){
cin>>x>>y>>c;
if(c[0]=='o')tc=0;
else tc=1;
fx=0;
fy=0;

for(j=0;j<sc;j++){
next=e[j][1];
while(next!=-1){
if(e[j][0]==x-1){
fx=1;
cx=e[j][1];
}else if(e[j][0]==y){
fy=1;
cy=e[j][1];
}else{
}
next=e[next][1];
}
}

if(fx==1&&fy==1){

if(cx/2==cy/2){
if((cx-cy)*(cx-cy)==tc){
}
else{
cout<<"i"<<endl;
goto out;
}
}

else{

if(tc==0){
}
else{
if(cx%2==0)cx++;
else cx--;
e[l[cx]][1]=e[cy][1];
l[cx]=l[cy];
e[cy][1]=-1;
}

}

}

else if(fx==1){
if(tc==0){}
else{
if(cx%2==0)cx++;
else cx--;
}
a[t][0]=y;
a[t][1]=cx;
if(e[cx][1]==-1)l[cx]=te;
e[te][0]=y;
e[te][1]=e[cx][1];
e[cx][1]=te;
te++;
t++;
}else if(fy==1){
if(tc==0){}
else{
if(cy%2==0)cy++;
else cy--;
}
a[t][0]=x-1;
a[t][1]=cy;
if(e[cy][1]==-1)l[cy]=te;
e[te][0]=x-1;
e[te][1]=e[cy][1];
e[cy][1]=te;
te++;
t++;
}else{
if(sc%2==1)sc++;
a[t][0]=x-1;
a[t][1]=sc;
if(e[sc][1]==-1)l[sc]=te;
e[te][0]=x-1;
e[te][1]=e[sc][1];
e[sc][1]=te;
te++;
t++;
if(tc==1)sc++;
a[t][0]=y;
a[t][1]=sc;
if(e[sc][1]==-1)l[sc]=te;
e[te][0]=y;
e[te][1]=e[sc][1];
e[sc][1]=te;
te++;
t++;
sc++;
}
}
cout<<n<<endl;
out://
}
}
