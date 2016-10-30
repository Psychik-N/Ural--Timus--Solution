#include <stdio.h>
int main(){
    int a,b,c,x,y,z,i,j,n,m,bi,bj,bv=-1,u[300],v[300];
    scanf("%d%d%d%d",&a,&b,&c,&n);
    for(i=1;i<=n;i++)scanf("%d%d",u+i,v+i);
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&z);
        if(x==1){
            if(y<=a&&b+z>bv){
                bv=b+z;
                bi=i;
                bj=-1;
            }
        }else if(a*2>=y){
            for(j=1;j<=n;j++)if(u[j]*2>=y&&c+v[j]+z>bv){
                bv=c+v[j]+z;
                bi=i;
                bj=j;
            }
        }
    }
    if(bv==-1)puts("Forget about apartments. Live in the dormitory.");
    else if(bj==-1)printf("You should rent the apartment #%d alone.\n",bi);
    else printf("You should rent the apartment #%d with the friend #%d.\n",bi,bj);
    return 0;
}
