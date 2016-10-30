#include <stdio.h>
#include <stdlib.h>
struct P{
int s;
char c;
struct P *n;
}*h,*w,*t,*l,*t2;
int main(){
int i,n,s,e,m=-1;
char c;
h=malloc(sizeof(struct P));
t=malloc(sizeof(struct P));
h->s=0;
h->c='w';
h->n=t;
t->s=1000000000;
t->c='b';
t->n=0;
scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%d %d %c",&s,&e,&c);
w=h;
while(w->s<s){
l=w;
w=w->n;
}
while(w->s<e){
t=w;
w=w->n;
free(t);
}
t=malloc(sizeof(struct P));
t->s=s;
t->c=c;
l->n=t;
if(w->s==e){
t->n=w;
}else{
t2=malloc(sizeof(struct P));
t2->s=e;
t2->c=l->c;
t2->n=w;
t->n=t2;
}
}
l=w=h;
while(w->n!=0){
while(w->c=='w')w=w->n;
if(w->s-l->s>m){
m=w->s-l->s;
s=l->s;
e=w->s;
}
while(w->n!=0&&w->c=='b')w=w->n;
}
printf("%d %d",s,e);
}
