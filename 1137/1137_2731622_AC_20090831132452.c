#include <stdio.h>
#include <stdlib.h>
struct Edge{
int to;
int mark;
struct Edge *next;
}*edg[10010]={0};
int ol[10010],ll=0;
void go(int p){
     struct Edge *work=edg[p];
     while(work!=0){
       if(work->mark==0){
         work->mark=1;
         go(work->to);
       }
       work=work->next;
     }
     ol[ll]=p;
     ll++;
}
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
struct Edge *work;
n=ms();
for(i=0;i<n;i++){
k=ms();
tot+=k;
lst=ms();
for(j=0;j<k;j++){
in=ms();
work=malloc(sizeof(struct Edge));
work->to=in;
work->mark=0;
work->next=edg[lst];
edg[lst]=work;
lst=in;
}
}
printf("%d",tot);
go(1);
for(i=ll-1;i>=0;i--)printf(" %d",ol[i]);
}
