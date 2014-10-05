#include<stdio.h>
int n,w[21],minn=2000000000,sum=0;

void go(int a,int wei){
    if(a>n){
        int c;
        
        if(wei>sum/2)c=wei-(sum-wei);
        else c=sum-wei-wei;
        
        if(c<minn)minn=c;
        
        return;
    }
    a++;
    go(a,wei);
    go(a,wei+w[a]);
    a--;
}

int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        sum+=w[i];
    }
    go(1,0);
    printf("%d",minn);
}