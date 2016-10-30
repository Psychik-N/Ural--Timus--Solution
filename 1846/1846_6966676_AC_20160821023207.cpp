#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn  =  111111;
int sum[maxn<<2];
inline int  gcd(int a,int b)
{
    return a==0?b:gcd(b%a,a);
}
void update(int p,int v,int l,int r,int rt){
    if(l==r){
        sum[rt]=v;
        return ;
    }
    int m=(l+r)>>1;
    if(p<=m) update(p,v,lson);
    else update(p,v,rson);
    sum[rt]=gcd(sum[rt<<1],sum[rt<<1|1]);
}
int flag[100100], vis[100100], num[100010];
int main(){
    int n,i,j;
    char op[5];
    while(scanf("%d",&n)!=EOF){
        vector<int> val;
        memset(sum,0,sizeof(sum));
        for(i=1;i<=n;i++){
            scanf("%s%d",op,&num[i]);
            val.push_back(num[i]);
            flag[i]=(op[0]=='+');
        }
        sort(val.begin(),val.end());
        int tot=unique(val.begin(),val.end())-val.begin();
        int cnt=0;memset(vis,0,sizeof(vis));
        for(i=1;i<=n;i++){
            int pos=lower_bound(val.begin(),val.begin()+tot,num[i])-val.begin()+1;
            if(flag[i]){
                cnt++;
                vis[pos]++;//printf("pos=%d\n",pos);
                if(vis[pos]==1) update(pos,val[pos-1],1,tot,1);//val[]的下标从0开始
            }
            else{
                cnt--;
                vis[pos]--;
                if(vis[pos]==0) update(pos,0,1,tot,1);
            }
            if(cnt==0) printf("1\n");
            else printf("%d\n",sum[1]);
        }
    }
    return 0;
}
