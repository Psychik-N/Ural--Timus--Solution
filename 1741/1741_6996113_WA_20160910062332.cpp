#include <stdio.h>
#include <limits.h>
typedef long long ll;
int count[20001][2]={0};
struct Edge{
    int to;
    int type;
    int len;
    Edge *next;
    Edge(int to,int type,int len,Edge *next,int add=1){
        this->to=to;
        this->type=type;
        this->len=len;
        this->next=next;
        count[to][type]+=add;
    }
}*edge[20001][2]={0};
ll f[20001][2];
int s[40001][2],sl=0;
void min(ll &a,ll b){
    a=a<=b?a:b;
}
int main(){
    int n,m,x,y,d;
    char st[15];
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)for(int j=0;j<2;j++)f[i][j]=LLONG_MAX;
    f[1][0]=0;
    for(int i=0;i<m;i++){
        scanf("%d%d%d%s",&x,&y,&d,st);
        if(st[0]=='L')edge[x][0]=new Edge(y,0,d,edge[x][0]);
        else if(st[0]=='P'){
            edge[x][0]=new Edge(y,1,d,edge[x][0]);
            edge[x][1]=new Edge(y,1,d,edge[x][1],0);
        }else{
            edge[x][0]=new Edge(y,0,d,edge[x][0]);
            edge[x][1]=new Edge(y,0,d,edge[x][1],0);
        }
    }
    s[0][0]=1;
    s[0][1]=0;
    sl=1;
    while(sl-->0){
        x=s[sl][0];
        y=s[sl][1];
        Edge *w=edge[x][y];
        while(w){
            min(f[w->to][w->type],f[x][y]+w->len);
            if(--count[w->to][w->type]==0){
                s[sl][0]=w->to;
                s[sl][1]=w->type;
                sl++;
            }
            w=w->next;
        }
    }
    min(f[n][0],f[n][1]);
    if(f[n][0]==LLONG_MAX)puts("Offline");
    else printf("Online\n%lld\n",f[n][0]);
    return 0;
}
