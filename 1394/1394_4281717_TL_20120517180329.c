#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ps 200
#define cr 60
#define mr1 1
#define mr2 10
#define ke 10
int pp[2][502][100],n,m,cs[2][502][10],on=0,fv[2][502],c[100],cd[10],*b1[2]={pp[0][500],pp[1][500]},
*b2[2]={pp[0][501],pp[1][501]},xz[130000]={0},id[500],gn=0;
int cmp1(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int cmp2(const void *a,const void *b){
    return fv[*(int*)a]-fv[*(int*)b];
}
void swap(int a,int b){
     int i,t;
     t=fv[on][a];
     fv[on][a]=fv[on][b];
     fv[on][b]=t;
     for(i=0;i<n;i++){
       t=pp[on][a][i];
       pp[on][a][i]=pp[on][b][i];
       pp[on][b][i]=t;
     }
     for(i=0;i<m;i++){
       t=cs[on][a][i];
       cs[on][a][i]=cs[on][b][i];
       cs[on][b][i]=t;
     }
}
void out(int x){
     int i,j,tt[10]={0};
     for(i=0;i<n;i++)tt[pp[on][x][i]]++;
     for(i=0;i<m;i++){
       printf("%d\n",tt[i]);
       for(j=0;j<n;j++)if(pp[on][x][j]==i)printf("%d ",c[j]);
       printf("\n");
     }
     exit(0);
}
void cal(int x){
     int i,t=0,tt[10]={0};
     for(i=0;i<n;i++)if(pp[on][x][i]!=-1){
       t+=c[i];
       tt[pp[on][x][i]]+=c[i];
     }
     fv[on][x]=t;
     for(i=0;i<m;i++)cs[on][x][i]=tt[i];
     for(i=0;i<m;i++)if(tt[i]!=cd[i])return;
     out(x);
}
void adj(int x){
     int i,j,t,bv;
     cal(x);
     for(i=0;i<n;i++){
       t=pp[on][x][i];
       if(t!=-1&&cs[on][x][t]>cd[t]){
         pp[on][x][i]=-1;
         cs[on][x][t]-=c[i];
         fv[on][x]-=c[i];
       }
     }
     for(i=0;i<n;i++){
       if(pp[on][x][i]!=-1)continue;
       bv=-1;
       for(j=0;j<m;j++)if(cd[j]-cs[on][x][j]-c[i]>bv){
         bv=cd[j]-cs[on][x][j]-c[i];
         t=j;
       }
       if(bv==-1)continue;
       cs[on][x][j]+=c[i];
       fv[on][x]+=c[i];
       pp[on][x][i]=t;
     }
}
void gen(){
     int i,j,a;
     for(i=0;i<ps;i++){
       if(i<ps-ke)a=id[(rand()*32768+rand())%((ps+1)*ps/2)];
       else a=ps-i-1;
       for(j=0;j<n;j++)pp[!on][i][j]=pp[on][a][j];
       fv[!on][i]=fv[on][a];
       for(j=0;j<m;j++)cs[!on][i][j]=cs[on][a][j];
     }
}
void cross(){
     int i,j,a;
     for(i=0;i<ps;i++){
       if(rand()%100>=cr)continue;
       a=rand()%(ps/2);
       if(i>=ps/2)a+=ps/2;
       for(j=0;j<n;j++){
         if(rand()%2){
           b1[on][j]=pp[on][i][j];
           b2[on][j]=pp[on][a][j];
         }else{
           b1[on][j]=pp[on][a][j];
           b2[on][j]=pp[on][i][j];
         }
       }
       adj(500);
       adj(501);
       if(fv[on][501]>fv[on][500])swap(500,501);
       if(fv[on][i]<fv[on][500])swap(i,500);
       if(fv[on][501]>fv[on][500])swap(500,501);
       if(fv[on][a]<fv[on][500])swap(a,500);
     }
}
void mut(){
     int i,j;
     for(i=0;i<ps;i++){
       for(j=0;j<n;j++)if(rand()%100<mr1)pp[on][i][j]=rand()%m;
       adj(i);
     }
     for(i=0;i<ps;i++){
       if(rand()%100>=mr2)continue;
       for(j=0;j<n;j++)if(rand()%2)pp[on][i][j]=rand()%m;
       adj(i);
     }
}
int main(){
    int i,j,p=0;
    srand(time(NULL));
    for(i=0;i<ps;i++)for(j=0;j<=i;j++)xz[p++]=i;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%d",&c[i]);
    qsort(c,n,4,cmp1);
    for(i=0;i<m;i++)scanf("%d",&cd[i]);
    for(i=0;i<ps;i++)for(j=0;j<n;j++)pp[0][i][j]=rand()%m;
    for(i=0;i<ps;i++)adj(i);
    while(1){
      for(i=0;i<ps;i++){
        id[i]=i;
        cal(i);
      }
      qsort(id,n,4,cmp2);
      gen();
      on=!on;
      cross();
      mut();
      gn++;
    }
}
