#include<iostream>
using namespace std;
int p[40000]={0},q[110000][2]={0},ans[110000]={0},rp[4000]={0},pp=0,list[33000][102]={0},now=0,ti,nn=0;
int main(){
    int nt,i,j;
    for(i=2;i<=33000;i++){
        if(p[i]==1)continue;
        for(j=i+i;j<=33000;j+=i)p[j]=1;
    }
    for(i=2;i<=33000;i++){
        if(p[i]==0){
            pp++;
            rp[pp]=i;
            p[i]=pp;
        }
    }
    cin>>nt;
    for(i=1;i<=nt;i++){
        cin>>q[i][0]>>q[i][1];
        q[i][0]%=q[i][1];
    }
    for(now=0;now<=pp;now+=100){
        nn++;
        for(i=now+1;i<=now+100;i++){
            for(j=1;j<rp[i];j++){
                list[(j*j)%rp[i]][i-now]=j+nn*100000;
            }
        }
        ti=i;
        for(i=1;i<=nt;i++){
            if(q[i][1]>=rp[now]&&q[i][1]<rp[ti]&&list[q[i][0]][p[q[i][1]]-now]/100000==nn){
                ans[i]=list[q[i][0]][p[q[i][1]]-now]-nn*100000;
            }
        }
    }
    for(i=1;i<=nt;i++){
        if(q[i][0]==1)cout<<1<<" "<<q[i][1]-1<<endl;
        else{
            if(ans[i]==0)cout<<"No root"<<endl;
            else cout<<q[i][1]-ans[i]<<" "<<ans[i]<<endl;
        }
    }
    system("pause");    
}
