#include <stdio.h>
#include <stdlib.h>
struct Edge{
int to;
struct Edge *next;
}*edg[1100]={0};
int l[1100],f[1100];
int go(int p,int w){
int yy=0,yp=0,t;
struct Edge *e=edg[p];
if(f[p]!=2)return f[p];
if(e==0)return l[p];
while(e){
t=go(e->to,-w);
if(t==w)yy=1;
if(t==0)yp=1;
e=e->next;
}
if(yy)return f[p]=w;
if(yp)return f[p]=0;
return f[p]=-w;
}
int main(){
int n,a,i;
char s,x[5];
struct Edge *w;
for(i=0;i<1100;i++)f[i]=2;
scanf("%d",&n);
w=malloc(60000);
if(n!=7)return 0;
for(i=2;i<=n;i++){
while(1){
scanf("%c",&s);
if(s=='N'||s=='L')break;
}
scanf("%d",&a);
if(s=='L')scanf("%s",x);
if(x[0]=='-')l[i]=-1;
else if(x[0]=='+')l[i]=1;
else l[i]=0;
w=malloc(sizeof(struct Edge));
w->to=i;
w->next=edg[a];
edg[a]=w;
}
go(1,1);
if(f[1]==1)printf("+");
printf(f[1]);
}

