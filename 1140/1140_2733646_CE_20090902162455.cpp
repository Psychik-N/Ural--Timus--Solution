#include<iostream>
using namespace std;

int abs(int a){
if(a>=0)return a;
return -a;
}

int sgn(int a){
if(a>=0)return 1;
return -1;
}

int main() {
int x=0,y=0,n,i,j,t;
char c;
cin>>n;
for(i=1;i<=n;i++){
cin>>c>>t;
for(j=1;j<=abs(t);j++){
if(c=='X')y+=sgn(t);
else if(c=='Y'){y+=sgn(t);x+=sgn(t);}
else x+=sgn(t);
}
}
if(x==0&&y==0){
cout<<0;
}
else if(x==0){
cout<<1<<endl<<"X"<<" "<<-y;
}
else if(y==0){
cout<<1<<endl<<"Y"<<" "<<-x;
}
else if(x==y){
cout<<1<<endl<<"Z"<<" "<<-x;
}
else if((x>0&&y>0&&x<y)||(x<0&&y<0&&x>y)){
cout<<2<<endl<<"Y"<<" "<<-x<<endl<<"X"<<" "<<-y+x;
}
else if((x>0&&y>0&&x>y)||(x<0&&y<0&&x<y)){
cout<<2<<endl<<"Y"<<" "<<-y<<endl<<"Z"<<" "<<-x+y;
}
else {
cout<<2<<endl<<"X"<