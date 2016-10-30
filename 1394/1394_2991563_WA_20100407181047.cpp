#include<stdio.h>
#include <stdlib.h> 
#include <time.h>
#include<iostream>
using namespace std;
int n,m,a[150],b[150],pb[150],c[150],d[150],pc[150],g[150],x,left1,s,m1,back;
int ta[150],tb[150],sp=0;
char cr[20000]={1};
void nxt();
void rnd(){
    int i,j,rd=rand()%500+1;
    for(i=1;i<=n;i++){ta[i]=(rand() % 500-200)*a[i]+2000;}
    for(i=1;i<=m;i++){tb[i]=(rand() % 500+500)*b[i];}
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(ta[i]>ta[j]){swap(a[i],a[j]);swap(ta[i],ta[j]);}
    for(i=1;i<=m;i++)for(j=1;j<=m;j++)if(tb[i]<tb[j]){swap(b[i],b[j]);swap(tb[i],tb[j]);swap(pb[i],pb[j]);}
}
void go(){
    if(sp==200000)nxt();
    sp++;
    int i,j;
    if(x==m1){
        int e=1;
        for(i=1;i<=n;i++)d[c[i]]++;
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(c[i]<c[j]){swap(c[i],c[j]);swap(pc[i],pc[j]);}
        for(i=1;i<=m;i++){
            printf("%d\n",d[i]);
            for(j=1;j<=d[i];j++)printf("%d ",pc[e++]);
            printf("\n");
        }
        exit(0);
    }
    for(i=s;i<=n;i++){
        if(c[i]||left1<a[i])continue;
        c[i]=pb[x];
        pc[i]=a[i];
        if(left1==a[i]){
x++;
left1=b[x];
back=s;
s=1;
if(cr[left1])go();
x--;
left1=a[i];
s=back;
}
        else{
left1-=a[i];
back=s;
s=i+1;
if(cr[left1])go();
left1+=a[i];
s=back;
}
        c[i]=0;
    }
}

void nxt(){
int i;
        sp=0;
        rnd();
        for(i=0;i<150;i++)d[i]=c[i]=0;
s=x=1;
left1=b[1];
        go();
    }

int main(){
    int i,j;
    srand( (unsigned)time( NULL ) ); 
    scanf("%d%d",&n,&m);
m1=m+1;
    for(i=1;i<=n;i++){scanf("%d",&a[i]);}
    for(i=1;i<=m;i++){scanf("%d",&b[i]);pb[i]=i;}
for(i=1;i<=n;i++)for(j=10000;j>=0;j--)if(cr[j]==1)cr[j+b[i]]=1;
    nxt();
}
