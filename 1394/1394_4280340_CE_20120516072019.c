#include<stdio.h>
#include <stdlib.h>
#include <time.h>
int n,m,a[150],b[150],pb[150],c[150],d[150],pc[150]
,g[150],x,left1,s,m1,sf[15],v=0;
int ta[150],tb[150],sp=0,fm[11][150]={0},fl[11][150]= {0},bf[11][150]={0};
int mynum[11]={0};
int bag[110][30000]={0},syg[110][30000]={0},from
[110][30000]={0},y[110][30000]={0},lbl[160],lbr[160];
int bagskip[110]={0},nomove[15]={0},hold[150]={0}
,fp[150]; char cr[20000]={1};
void nxt();
void swap(int *aa,int *bb){
     int t=*aa;
     *aa=*bb;
     *bb=t; }
void rnd(){
    int i,j;
    for(i=1;i<=m;i++)tb[i]=rand();
    for(i=1;i<=m;i++)for(j=m;j>=i+1;j--)if(tb[j]<tb[j-1]){
        swap(&b[j],&b[j-1]);swap(&tb[j],&tb[j-1]);swap (&pb[j],&pb[j-1]);swap(&nomove[i],&nomove[j]);
    }
}
void go(){
    int i,j,back,xback;
    int f1,f2;     if(sp==2000)return;
    sp++;
    if(x==m1){
        int e=1;
        for(i=1;i<=n;i++)d[c[i]]++;
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(c[i]<c[j]) {swap(&c[i],&c[j]);swap(&pc[i],&pc[j]);}
        for(i=1;i<=m;i++){
            printf("%d\n",d[i]);
            for(j=1;j<=d[i];j++)printf("%d ",pc[e++]);
            printf("\n");
        }         exit(0);
    }
    if(bag[s][left1]==1){
        int flag=1,k,t,bagback;
        bf[x][0]=0;
        k=left1;         j=syg[s][k];
        while(k>0){
            t=fp[a[j]]+bagskip[a[j]];
            if(a[j]!=a[t]){
                flag=0;
                break;             }
            bf[x][0]++;
            bf[x][bf[x][0]]=t;
            c[t]=pb[x];
            pc[t]=a[t];
            lbr[lbl[t]]=lbr[t];             lbl[lbr[t]]=lbl[t];
            bagskip[a[j]]++;
            k-=a[j];
            j=from[j][k+a[j]];
        }
        if(flag){             xback=x;
            while(nomove[++x]==1);
            bagback=left1;
            left1=b[x];
            back=s;
            s=sf[pb[x]];             mynum[x]++;
            go();
            s=back;
            x=xback;
            left1=bagback;
        }         for(i=1;i<=bf[x][0];i++){
            c[bf[x][i]]=0;
            bagskip[a[bf[x][i]]]--;
            lbr[lbl[bf[x][i]]]=bf[x][i];
            lbl[lbr[bf[x][i]]]=bf[x][i];
        }         return;
    }
    f1 = fl[x][0];
    i=s;
    while(i<=n){
        if(bag[i][left1]==0)break;         if(c[i]||left1<a[i]||fm[x][a[i]]==mynum[x]){i=lbr[i]
;continue;}
        f2 = fl[x][0];
        c[i]=pb[x];
        pc[i]=a[i];
        back=s;         if(left1==a[i]){
            xback=x;
            while(nomove[++x]==1);
            left1=b[x];
            s=sf[pb[x]];
            mynum[x]++;             bagskip[a[i]]++;
            go();
            bagskip[a[i]]--;
            x=xback;
            left1=a[i];
        }         else{
            for (j=1; j<=f2; j++) {
                if (fl[x][j] > a[i] && fm[x][fl[x][j] - a[i]] !
=mynum[x]) {
                fm[x][fl[x][j] - a[i]] = mynum[x];
                fl[x][0]++;                 fl[x][fl[x][0]] = fl[x][j] - a[i];
                }
            }
            left1-=a[i];
            s=i+1;
            lbr[lbl[i]]=lbr[i];             lbl[lbr[i]]=lbl[i];
            bagskip[a[i]]++;
            go();
            bagskip[a[i]]--;
            lbr[lbl[i]]=i;
            lbl[lbr[i]]=i;             left1+=a[i];
            for (j=f2+1; j<=fl[x][0]; j++) {
            fm[x][fl[x][j]] = 0;
         }
         fl[x][0] = f2;
         if (fm[x][a[i]] !=mynum[x]) {             fm[x][a[i]] = mynum[x];
            fl[x][0]++;
            fl[x][fl[x][0]] = a[i];
         }
        }
        s=back;         c[i]=0;
        i=lbr[i];
    }
    for (i=f1+1; i<=fl[x][0]; i++) {
        fm[x][fl[x][i]] = 0;
    }     fl[x][0] = f1;
} void nxt(){
    int i;
    sp=0;
    rnd();
    for(i=0;i<150;i++){
        d[i]=0;         if(!hold[i])c[i]=0;
    }
    s=1;
    x=0;
    while(nomove[++x]==1);
    left1=b[x];     for(i=0;i<11;i++)mynum[i]=100;
    go();
} int main(){
    int i,j,k,t;
    srand( (unsigned)time( NULL ) );
    scanf("%d%d",&n,&m);
    m1=m+1;
    for(i=1;i<=n;i++){scanf("%d",&a[i]);}     for(i=1;i<=m;i++){scanf("%d",&b[i]);pb[i]=i;}
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(a[i]>a[j]){swap
(&a[i],&a[j]);}
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(a[j]<=b[i]){                 sf[i]=j;
                break;
            }
        }
    }
    bag[n+1][0]=1;syg[n+1][0]=n+1;     for(k=n;k>=1;k--){
        for(j=10000;j>=0;j--)if(bag[k+1][j]!=0){
            if(bag[k+1][j]==1){
                bag[k][j+a[k]]+=bag[k+1][j];
                y[k][j+a[k]]=1;
                from[k][j+a[k]]=syg[k+1][j];                 syg[k][j+a[k]]=k;
                syg[k][j]=syg[k+1][j];
                if(a[k]!=a[k+1]||y[k+1][j]==0){
                    bag[k][j]+=bag[k+1][j];
                }else{
                    bag[k][j]=0;                 }
            }else{
                bag[k][j+a[k]]=bag[k+1][j];
                bag[k][j]=bag[k+1][j];
            }
        }     }
    for(i=0;i<=150;i++){lbl[i+1]=i;lbr[i]=i+1;}
    for(i=n;i>=1;i--)fp[a[i]]=i;
    for(i=1;i<=m;i++){
        if(bag[1][b[i]]==1){
            nomove[i]=1;             k=b[i];
            j=syg[1][k];
            while(k>0){
                t=fp[a[j]]+bagskip[a[j]];
                hold[t]=1;
                c[t]=pb[i];                 pc[t]=a[t];
                bagskip[a[j]]++;
                lbr[lbl[t]]=lbr[t];
                lbl[lbr[t]]=lbl[t];
                k-=a[j];
                j=from[j][k+a[j]];             }
        }
    }
    for(i=1;i<=10000000;i++){
        nxt();
        //printf("%d\n",i);     }
}