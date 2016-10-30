#include<stdio.h>
#include <stdlib.h> 
#include <time.h>
#include<iostream>
using namespace std;
int n,m,a[150],b[150],pb[150],c[150],d[150],pc[150],g[150],x,left1,s,m1,back,sf[15],v=0;
int ta[150],tb[150],sp=0,fm[11][150]={0},fl[11][150]={0};
int mynum[11]={0};
char cr[20000]={1};
void nxt();
void swap(int *aa,int *bb){
     int t=*aa;
     *aa=*bb;
     *bb=t;
}
void rnd(){
    int i,j;
    for(i=1;i<=m;i++)tb[i]=rand();
    for(i=1;i<=m;i++)for(j=m;j>=i+1;j--)if(tb[j]<tb[j-1]){swap(b[j],b[j-1]);swap(tb[j],tb[j-1]);swap(pb[j],pb[j-1]);}
}
void go(){
    if(sp==25000)return;
    sp++;
    int i,j;
    int f1,f2;
    if(x==m1){
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
    f1 = fl[x][0];
    for(i=s;i<=n;i++){
        if(c[i]||left1<a[i]||fm[x][a[i]]==mynum[x])continue;
        f2 = fl[x][0];
        c[i]=pb[x];
        pc[i]=a[i];
        back=s;
        if(left1==a[i]){
            x++;
            left1=b[x];
            s=sf[pb[x]];
            //if(cr[left1]){
                            mynum[x]++;
                //memset(fm[x], 0, 600);
                go();
            //}
            x--;
            left1=a[i];
        }
        else{
            for (j=1; j<=f2; j++) {
                if (fl[x][j] > a[i] && fm[x][fl[x][j] - a[i]] !=mynum[x]) {
    				fm[x][fl[x][j] - a[i]] = mynum[x];
    				fl[x][0]++;
    				fl[x][fl[x][0]] = fl[x][j] - a[i];
                }
            }
            left1-=a[i];
            s=i+1;
            if(cr[left1])go();
            left1+=a[i];
            for (int j=f2+1; j<=fl[x][0]; j++) {
				fm[x][fl[x][j]] = 0;
			}
			fl[x][0] = f2;
			if (fm[x][a[i]] !=mynum[x]) {
				fm[x][a[i]] = mynum[x];
				fl[x][0]++;
				fl[x][fl[x][0]] = a[i];				
			}
        }
        s=back;
        c[i]=0;
    }
    for (int i=f1+1; i<=fl[x][0]; i++) {
		fm[x][fl[x][i]] = 0;
	}
	fl[x][0] = f1;
}


void nxt(){
    int i;
    sp=0;
    rnd();
    for(i=0;i<150;i++)d[i]=c[i]=0;
    s=x=1;
    left1=b[1];
    for(i=0;i<11;i++)mynum[i]=100;
    go();
}




int go(int x,int left,int s){
    int i,j;
    v++;
    if(v>1500000){
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(a[i]>a[j]){swap(&a[i],&a[j]);}
        for(i=1;i<=m;i++)for(j=1;j<=m;j++)if(b[i]>b[j]){swap(&b[i],&b[j]);swap(&pb[i],&pb[j]);}
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
    srand( (unsigned)time( NULL ) ); 
    scanf("%d%d",&n,&m);
    m1=m+1;
    for(i=1;i<=n;i++){scanf("%d",&a[i]);}
    for(i=1;i<=m;i++){scanf("%d",&b[i]);pb[i]=i;}
    for(i=1;i<=n;i++)for(j=10000;j>=0;j--)if(cr[j]==1)cr[j+a[i]]=1;
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(a[i]>a[j]){swap(a[i],a[j]);}
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(a[j]<=b[i]){
                sf[i]=j;
                break;
            }
        }
    }
    for(i=1;i<=100;i++)nxt();
    j=go(1,b[1],1);j=go(1,b[1],1);j=go(1,b[1],1);j=go(1,b[1],1);j=go(1,b[1],1);
    for(i=1;i<=100;i++)nxt();
    j=go(1,b[1],1);j=go(1,b[1],1);j=go(1,b[1],1);j=go(1,b[1],1);j=go(1,b[1],1);
    for(i=1;i<=100;i++)nxt();
    j=go(1,b[1],1);j=go(1,b[1],1);j=go(1,b[1],1);j=go(1,b[1],1);j=go(1,b[1],1);
    for(i=1;i<=100;i++)nxt();
    j=go(1,b[1],1);j=go(1,b[1],1);j=go(1,b[1],1);j=go(1,b[1],1);j=go(1,b[1],1);
    for(i=1;i<=100;i++)nxt();
    j=go(1,b[1],1);j=go(1,b[1],1);j=go(1,b[1],1);j=go(1,b[1],1);j=go(1,b[1],1);
    for(i=1;i<=100;i++)nxt();
    j=go(1,b[1],1);j=go(1,b[1],1);j=go(1,b[1],1);j=go(1,b[1],1);j=go(1,b[1],1);
    
}











