#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 80010
#pragma comment(linker, "/STACK:16777216")
struct Edge{
       int to,len;
       struct Edge *next;
}*edg[M]={0},*ql[M]={0};
int m1[M]={0},m2[M]={0},dis[M],ans[M],head[M];
void dfs(int p,int l){
     struct Edge *t=edg[p];
     dis[p]=l;
     m1[p]=1;
     while(t){
       if(m1[t->to]==0)dfs(t->to,l+t->len);
       t=t->next;
     }
}
void zip(int p){
     int w=p,h,t;
     while(head[w]!=w)w=head[w];
     h=w;
     w=p;
     while(w!=h){
       t=w;
       w=head[w];
       head[t]=h;
     }
}
void conn(int a,int b){
     head[a]=b;
}
int find(int p){
    zip(p);
    return head[p];
}
void tarjan(int p){
     struct Edge *t=edg[p],*w=ql[p];
     m2[p]=1;
     while(t){
       if(m2[t->to]==0){
         tarjan(t->to);
         conn(t->to,p);
       }
       t=t->next;
     }
     while(w){
//     printf(" %d\n",p);
       if(m2[w->to])ans[w->len]=dis[p]+dis[w->to]-2*dis[find(w->to)];
//     printf("+%d\n",p);
       w=w->next;
//     printf("-%d\n",p);
     }
}
int main(){
    int n,m,i,a,b,r,c;
    struct Edge *t;
    srand(time(0));
    scanf("%d",&n);
    for(i=0;i<n;i++)head[i]=i;
    for(i=1;i<n;i++){
      scanf("%d%d%d",&a,&b,&c);
      t=malloc(sizeof(struct Edge));
      t->to=b;
      t->len=c;
      t->next=edg[a];
      edg[a]=t;
      t=malloc(sizeof(struct Edge));
      t->to=a;
      t->len=c;
      t->next=edg[b];
      edg[b]=t;
    }
    dfs(r=rand()%n,0);
    scanf("%d",&m);
    for(i=0;i<m;i++){
      scanf("%d%d",&a,&b);
      t=malloc(sizeof(struct Edge));
      t->to=a;
      t->len=i;
      t->next=ql[b];
      ql[b]=t;
      t=malloc(sizeof(struct Edge));
      t->to=b;
      t->len=i;
      t->next=ql[a];
      ql[a]=t;
    }
    tarjan(r);
    for(i=0;i<m;i++)printf("%d\n",ans[i]);
}

