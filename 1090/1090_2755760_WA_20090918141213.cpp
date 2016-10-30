#include<iostream>
using namespace std;
int n,m,h[21][10010],jp[21]={0},t[33000][3],mj=0,mi=1;

void createTree(int index,int s,int e){
    t[index][1]=s;
    t[index][2]=e;
    if(s==e)return;
    createTree(index*2,s,(s+e)/2);
    createTree(index*2+1,(s+e)/2+1,e);
}

void tSet(int index,int s,int e){
    if(e<s)return;
    if(t[index][1]==s&&t[index][2]==e){
        t[index][0]++;
    }else if(e<=(t[index][1]+t[index][2])/2){
        tSet(index*2,s,e);
    }else if(s>(t[index][1]+t[index][2])/2){
        tSet(index*2+1,s,e);
    }else{
        tSet(index*2,s,(t[index][1]+t[index][2])/2);
        tSet(index*2+1,(t[index][1]+t[index][2])/2+1,e);
    }
}

int tCheck(int index,int j){
    if(j<1)return 0;
    int rtn=t[index][0];
    if(t[index][1]==t[index][2])return rtn;
    if(j<=(t[index][1]+t[index][2])/2){
        rtn+=tCheck(index*2,j);
    }else{
        rtn+=tCheck(index*2+1,j);
    }
    return rtn;
}

int main(){
    cin>>n>>m;
    int i,j;
    createTree(1,1,10000);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin>>h[i][j];
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=32999;j++)t[j][0]=0;
        for(j=1;j<=m;j++){
            tSet(1,1,h[i][j]-1);
            jp[i]+=tCheck(1,h[i][j]);
        }
        if(jp[i]>mj){
            mj=jp[i];
            mi=i;
        }
    }
    cout<<mi;
    system("pause");
}
    
