#include<stdio.h>
#include <stdlib.h> 
#include <time.h>
#include<iostream>
using namespace std;
int n,m,a[150],b[150],pb[150],c[150],d[150],pc[150],g[150];
int ta[150],tb[150],sp=0;

void rnd(){
    int i,j;
    for(i=1;i<=n;i++){ta[i]=(rand() % 5000)*a[i];}
    for(i=1;i<=m;i++){tb[i]=(rand() % 5000)*b[i];}
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(ta[i]<ta[j]){swap(a[i],a[j]);swap(ta[i],ta[j]);}
    for(i=1;i<=m;i++)for(j=1;j<=m;j++)if(tb[i]<tb[j]){swap(b[i],b[j]);swap(tb[i],tb[j]);swap(pb[i],pb[j]);}
}
int go(int x,int left,int s){
    if(sp>2000000)return 0;
    sp++;
    int i,j;
    if(x==m+1){
        int e=1;
        for(i=1;i<=n;i++)d[c[i]]++;
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(c[i]<c[j]){swap(c[i],c[j]);swap(pc[i],pc[j]);}
        for(i=1;i<=m;i++){
            printf("%d\n",d[i]);
            for(j=1;j<=d[i];j++)printf("%d ",pc[e++]);
            printf("\n");
        }
        system("pause");
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



int main(){
    int i,j;
    srand( (unsigned)time( NULL ) ); 
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){scanf("%d",&a[i]);}
    for(i=1;i<=m;i++){scanf("%d",&b[i]);pb[i]=i;}
    while(1){
        sp=0;
        rnd();
        for(i=0;i<150;i++)d[i]=c[i]=0;
        go(1,b[1],1);
    }
}

