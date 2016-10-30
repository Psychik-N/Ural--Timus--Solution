#include<iostream>
using namespace std;
int n,m,a[150],b[150],pb[150],c[150]={0},d[150]={0},pc[150];
void go(int x,int left,int s){
    if(x==m+1){
        int i,j,e=1;
        for(i=1;i<=n;i++)d[c[i]]++;
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(c[i]<c[j]){swap(c[i],c[j]);swap(pc[i],pc[j]);}
        for(i=1;i<=m;i++){
            cout<<d[i]<<endl;
            for(j=1;j<=d[i];j++)cout<<pc[e++]<<" ";
            cout<<endl;
        }
        system("pause");
        exit(0);
    }
    int i;
    for(i=s;i<=n;i++){
        if(c[i]||left<a[i])continue;
        c[i]=pb[x];
        pc[i]=a[i];
        if(left==a[i])go(x+1,b[x+1],1);
        else go(x,left-a[i],i+1);
        c[i]=0;
    }
}
int main(){
    cin>>n>>m;
    int i,j;
    for(i=1;i<=n;i++){cin>>a[i];}
    for(i=1;i<=m;i++){cin>>b[i];pb[i]=i;}
    for(i=1;i<=m;i++)for(j=1;j<=m;j++)if(b[i]<b[j]){swap(b[i],b[j]);swap(pb[i],pb[j]);}
    go(1,b[1],1);
}
/*
5 2
4
10
2
5
3
11
13
*/
