#include<iostream>
using namespace std;
int n,s,map[200][200],from[200]={0},lx[200]={0},ly[200]={0},slack[200],vx[200]={0},vy[200]={0};

int path(int v){
    int i,t;
    vx[v]=1;
    for(i=1;i<=n;i++){
        if(vy[i])continue;
        t=lx[v]+ly[i]-map[v][i];
        if(t==0){
            vy[i]=1;
            if(from[i]==0||path(from[i])){
                from[i]=v;
                return 1;
            }
        }else if(t<slack[i]){
            slack[i]=t;
        }
    }
    return 0;
}

int km(){
    int i,j,d,ans=0;
    for(i=1;i<=n;i++){
        while(true){
            memset(vx,0,800);
            memset(vy,0,800);
            for(j=1;j<=n;j++)slack[j]=2000000000;
            if(path(i))break;
            d=2000000000;
            for(j=1;j<=n;j++){
                if(!vy[j]&&slack[j]<d)d=slack[j];
            }
            for(j=1;j<=n;j++){
                if(vx[j])lx[j]-=d;
                if(vy[j])ly[j]+=d;
            }
        }
    }
    for(i=1;i<=n;i++){
        ans+=map[from[i]][i];
    }
    return ans;
}

int main(){
    int i,j;
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>map[i][j];
            s+=map[i][j];
            if(map[i][j]>lx[i])lx[i]=map[i][j];
        }
    }
    cout<<s-km();
}
