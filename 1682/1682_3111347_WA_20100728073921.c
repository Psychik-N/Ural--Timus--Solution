#include <stdio.h>
#include <stdlib.h>
struct Item{
int num;
struct item *next;
}*i1[150010]={0};
int head[500010];
void zip(int a){
int t,w=0,h;
while(head[w]!=w)w=head[w];
h=w;
w=a;
while(head[w]!=h){
t=head[w];
head[w]=h;
w=t;
}
}
void link(int a,int b){
head[head[a]]=b;
}
int find(int a){
zip(a);
return head[a];
}
int main(){
int k,i=1,t,j;
struct Item *w1;
scanf("%d",&k);
for(i=0;i<k;i++){
t=i*i%k;
w1=malloc(8);
w1->num=i;
w1->next=i1[t];
i1[t]=w1;
}
while(1){
head[i]=i;
t=(k-i%k)%k;
w1=i1[t];
while(w1){
j=w1->num;
while(j<i){
if(find(i)==find(j))goto out;
link(i,j);
j+=k;
}
w1=w1->next;
}
j=(k-i*i%k)%k;
while(j<i){
if(find(i)==find(j))goto out;
link(i,j);
j+=k;
}
i++;
}
out:
printf("%d",i);
}

