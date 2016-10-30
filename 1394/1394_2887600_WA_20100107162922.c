#include<stdio.h>
#include <stdlib.h> 
int n,m,a[150],b[150],pb[150],c[150]={0},d[150]={0},pc[150],v=0;

void swap(int *aa,int *bb){
     int t=*aa;
     *aa=*bb;
     *bb=t;
}
int go(int x,int left,int s){
    int i,j;
    v++;
    if(v>10000000){
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(a[i]>a[j]){swap(&a[i],&a[j]);}
        for(i=1;i<=m;i++)for(j=1;j<=m;j++)if(b[i]<b[j]){swap(&b[i],&b[j]);swap(&pb[i],&pb[j]);}
        for(i=1;i<=n;i++)c[i]=0;
        v=0;
        return 1;
    }
    if(x==m+1){
        int e=1;
        for(i=1;i<=n;i++)d[c[i]]++;
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(c[i]<c[j]){swap(&c[i],&c[j]);swap(&pc[i],&pc[j]);}
        for(i=1;i<=m;i++){
            printf("%d\n",d[i]);
            for(j=1;j<=d[i];j++)printf("%d ",pc[e++]);
            printf("\n");
        }
        exit(0);
    }
    for(i=s;i<=n;i++){
        if(c[i]||left<a[i])continue;
        c[i]=pb[x];
        pc[i]=a[i];
        if(left==a[i])j=go(x+1,b[x+1],1);
        else j=go(x,left-a[i],i+1);
        if(j)return 1;
        c[i]=0;
    }
    return 0;
}


int go2(int x,int left,int s){
    int i,j;
    v++;
    if(v>3000000){
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(a[i]>a[j]){swap(&a[i],&a[j]);}
        for(i=1;i<=m;i++)for(j=1;j<=m;j++)if(b[i]<b[j]){swap(&b[i],&b[j]);swap(&pb[i],&pb[j]);}
        for(i=1;i<=n;i++)c[i]=0;
        v=0;
        return 1;
    }
    if(x==m+1){
        int e=1;
        for(i=1;i<=n;i++)d[c[i]]++;
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(c[i]<c[j]){swap(&c[i],&c[j]);swap(&pc[i],&pc[j]);}
        for(i=1;i<=m;i++){
            printf("%d\n",d[i]);
            for(j=1;j<=d[i];j++)printf("%d ",pc[e++]);
            printf("\n");
        }
        exit(0);
    }
    for(i=s;i<=n;i++){
        if(c[i]||left<a[i])continue;
        c[i]=pb[x];
        pc[i]=a[i];
        if(left==a[i])j=go2(x+1,b[x+1],1);
        else j=go2(x,left-a[i],i+1);
        if(j)return 1;
        c[i]=0;
    }
    return 0;
}
int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=m;i++){scanf("%d",&b[i]);pb[i]=i;}
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(a[i]<a[j]){swap(&a[i],&a[j]);}
    for(i=1;i<=m;i++)for(j=1;j<=m;j++)if(b[i]<b[j]){swap(&b[i],&b[j]);swap(&pb[i],&pb[j]);}
    j=go(1,b[1],1);
    go2(1,b[1],1);
}
