#include <stdio.h>
#include <stdlib.h>
struct Edge{
int to;
struct Edge *next;
}**edg,*work;
int ms(){
int s=0;
char c;
do{
c=getchar();
}while(c<'0'||c>'9');
s=c-'0';
while(1){
c=getchar();
if(c<'0'||c>'9')break;
s=s*10+c-'0';
}
return s;
}
int main(){
int n,k,tot=0,in,lst,i,j;
n=ms();
edg=malloc(sizeof(struct Edge*)*(n+1));
for(i=0;i<=n;i++)edg[i]=0;
for(i=0;i<n;i++){
k=ms();
tot+=k;
lst=ms();
for(j=0;j<k;j++){
in=ms;
work=malloc(sizeof(struct Edge));
work->to=in;
work->next=edg[lst];
edg[lst]=work;
lst=in;
}
}
printf("%d 1",tot);
work=edg[1];
k=1;
while(work!=0){
edg[k]=edg[k]->next;
k=work->to;
printf(" %d",k);
work=edg[k];
}
}
