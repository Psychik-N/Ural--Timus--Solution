#include<iostream>
using namespace std;
int x,y,k,b;
int f[50][50],a[50];
void init(){
    int i,j;
    f[0][0]=1;
    for(i=1;i<=31;i++){
        f[i][0]=f[i-1][0];
        for(j=1;j<=i;j++)
        f[i][j]=f[i-1][j]+f[i-1][j-1];
    }
}

int solve(int x){
    int i,ans=0;
    for(i=0;x!=0;i++){
        a[i]=x%b;
        x/=b;
    }
    i--;
    for(;i>=0;i--){
        if(a[i]>1){
            ans-=1;
            ans+=(1<<(i+1));
            break;
        }
        ans+=a[i]*(1<<i);
    }
    return ans;
}
int calc(int x){
    int i,sum=0,tot=0;
    x=solve(x);
    for(i=30;i>=0;i--){
        if(x&(1<<i)){
            x-=(1<<i);
            sum+=f[i][k-tot];
            tot++;
            if(tot==k){
                sum++;
                break;
            }
        }
    }
    return sum;
}

int main(){
    init();
    while(cin>>x>>y>>k>>b){
        cout<<calc(y)-calc(x-1);
    }
}