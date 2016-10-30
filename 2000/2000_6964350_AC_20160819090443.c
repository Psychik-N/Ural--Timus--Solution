#include <stdio.h>
int v[100001];
int main(){
    int n,i,x,y,s1=0,s2=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",v+i);
    scanf("%d%d",&x,&y);
    if(x==y){
        for(i=1;i<=x-1;i++)s1+=v[i];
        for(i=x+1;i<=n;i++)s2+=v[i];
        if(s1>=s2)printf("%d %d\n",s1+v[x],s2);
        else printf("%d %d\n",s2+v[x],s1);
    }else if(x<y){
        for(i=1;i<=(x+y)/2;i++)s1+=v[i];
        for(i=(x+y)/2+1;i<=n;i++)s2+=v[i];
        printf("%d %d\n",s1,s2);
    }else{
        for(i=1;i<=(x+y-1)/2;i++)s2+=v[i];
        for(i=(x+y-1)/2+1;i<=n;i++)s1+=v[i];
        printf("%d %d\n",s1,s2);
    }
    return 0;
}
