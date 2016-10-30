#include<stdio.h>
#include <stdlib.h> 
#include <time.h>
#include<iostream>
using namespace std;
int n,m,a[150],b[150],pb[150],c[150],d[150],pc[150],g[150],x,left1,s,m1,back,sf[15];
int ta[150],tb[150],sp=0,fail_mark[11][150]={0}, fail_list[11][150]={0};
char cr[20000]={1};
void nxt();
void rnd(){
    int i,j;
    //for(i=1;i<=n;i++){ta[i]=(rand()%500+1000)*a[i];}
    for(i=1;i<=m;i++){tb[i]=rand();}
    for(i=1;i<=m;i++)for(j=1;j<=m;j++)if(tb[i]<tb[j]){swap(b[i],b[j]);swap(tb[i],tb[j]);swap(pb[i],pb[j]);}
}
void go(){
    if(sp==500000)return;
    sp++;
    int i,j;
    int fail_num_bak1, fail_num_bak2;
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
    fail_num_bak1 = fail_list[x][0];
    for(i=s;i<=n;i++){
        if(c[i]||left1<a[i]||fail_mark[x][a[i]])continue;
        fail_num_bak2 = fail_list[x][0];
        c[i]=pb[x];
        pc[i]=a[i];
        back=s;
        if(left1==a[i]){
            x++;
            left1=b[x];
            s=sf[x];
            if(cr[left1]){
                memset(fail_mark[x], 0, 600);
                go();
            }
            x--;
            left1=a[i];
        }
        else{
            for (j=1; j<=fail_num_bak2; j++) {
                if (fail_list[x][j] > a[i] && fail_mark[x][fail_list[x][j] - a[i]] == 0) {
    				fail_mark[x][fail_list[x][j] - a[i]] = 1;
    				fail_list[x][0]++;
    				fail_list[x][fail_list[x][0]] = fail_list[x][j] - a[i];
                }
            }
            left1-=a[i];
            s=i+1;
            if(cr[left1])go();
            left1+=a[i];
            for (int j=fail_num_bak2+1; j<=fail_list[x][0]; j++) {
				fail_mark[x][fail_list[x][j]] = 0;
			}
			fail_list[x][0] = fail_num_bak2;
			if (fail_mark[x][a[i]] == 0) {
				fail_mark[x][a[i]] = 1;
				fail_list[x][0]++;
				fail_list[x][fail_list[x][0]] = a[i];				
			}
        }
            s=back;
        c[i]=0;
    }
    for (int i=fail_num_bak1+1; i<=fail_list[x][0]; i++) {
		fail_mark[x][fail_list[x][i]] = 0;
	}
	fail_list[x][0] = fail_num_bak1;
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
    for(i=1;i<=n;i++)for(j=10000;j>=0;j--)if(cr[j]==1)cr[j+a[i]]=1;
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(a[i]>a[j]){swap(a[i],a[j]);}
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(a[j]<b[i]){
                sf[i]=j;
                break;
            }
        }
    }
    go();
    while(1)nxt();
}


