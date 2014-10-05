#include<iostream>
using namespace std;
int d[120000]={0},a[120000],x=0,y=0,n,mark[120000]={0},mark2[120000]={0};
int main(){
int i,j,now,step;
cin>>n;
for(i=1;i<=n;i++){cin>>a[i];d[a[i]]++;}
for(i=1;i<=n;i++){
if(d[i]==0&&mark[i]==0){
step=1;
mark[i]=1;
mark2[i]=i;
now=a[i];
while(mark[now]==0){
step++;
mark[now]=step;
mark2[now]=i;
now=a[now];
}
if(mark2[now]!=i)x+=(step);
else x+=mark[now];
y++;
}
}

for(i=1;i<=n;i++){
if(mark[i]==0){
mark[i]=1;
now=a[i];
while(mark[now]==0){
mark[now]=1;
now=a[now];
}
x++;
y++;
}
}

cout<<y<<" "<<x;
}
