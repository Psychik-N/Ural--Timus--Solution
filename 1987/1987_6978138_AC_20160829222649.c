#include <stdio.h>
int s[100001][3],sl=0;
int in[100001][2];
int main(){
    int n,i,m,p,ip=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d%d",&in[i][0],&in[i][1]);
    scanf("%d",&m);
    while(m-->0){
        scanf("%d",&p);
        while(1){
            while(sl>0&&p>s[sl-1][1])sl--;
            while(ip<=n&&in[ip][0]<=p){
                s[sl][0]=in[ip][0];
                s[sl][1]=in[ip][1];
                s[sl][2]=ip++;
                sl++;
            }
            if(sl==0){
                printf("-1\n");
                break;
            }else if(s[sl-1][1]>=p){
                printf("%d\n",s[sl-1][2]);
                break;
            }
        }
    }
    return 0;
}
