#include<iostream>
using namespace std;
int n,i,j,k,a=0,b,mark[100000]={0},c[100]={0},d[100]={0},e;
void out(){
    for(b=1;b<100000;b++)a+=mark[b];
    cout<<a<<endl;
    for(b=1;b<100000;b++){
        if(mark[b])cout<<b<<" ";
    }
    system("pause");
}
int go(int x){
    int ans=0;
    while(x!=0){
        ans+=x%10;
        x/=10;
    }
    return ans;
}
int main(){
    cin>>n;
    for(i=1;i<100000;i++){
        if(n>go(i)){
            n-=go(i);
            mark[i]=1;
            c[go(i)]=i;
        }
        else goto y;
    }
    if(n!=0){
        cout<<-1;
        return 0;
    }
    y:;
    e=i;
    for(i=e;i<100000;i++){
        if(n==go(i)){
            mark[i]=1;
            out();
            return 0;
        }
    }
    for(i=e;i<100000;i++){
        if(go(i)-n>0&&c[go(i)-n]){
            mark[i]=1;
            mark[c[go(i)-n]]=0;
            out();
            return 0;
        }
    }
    cout<<-1;
}