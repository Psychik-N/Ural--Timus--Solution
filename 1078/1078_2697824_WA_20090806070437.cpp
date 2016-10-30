#include<iostream>
using namespace std;
//ifstream cin("1078.in");
//ofstream cout("1078.out");

int main(){
    int i,j,k,n,e[500][2],to[500]={0},len[500]={0},maxf=1;
    cin>>n;
    if(n==0){
        cout<<"0";
        return 0;
    }
    for(i=1;i<=n;i++)cin>>e[i][0]>>e[i][1];
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            for(k=1;k<=n;k++){
                if((e[j][0]>e[k][0])&&(e[j][1]<e[k][1])&&len[k]+1>len[j]){
                    len[j]=len[k]+1;
                    to[j]=k;
                }
            }
        }
    }
    for(i=1;i<=n;i++){
        if(len[i]>len[maxf])maxf=i;
    }
    cout<<maxf+1<<"\n";
    i=maxf;
    do{
        cout<<i<<" ";
        i=to[i];
    }while(i!=0);
}
        
    
