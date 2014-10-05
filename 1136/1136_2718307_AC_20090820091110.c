#include <stdio.h>
#include <stdlib.h>
struct Node{
       int num;
       struct Node *l;
       struct Node *r;
}*root=0;
int in[3010];
struct Node *build(int s,int e){
       struct Node *tr;
       int i,f=0;
       if(s>e)return 0;
       tr=malloc(sizeof(struct Node));
       tr->num=in[e];
       for(i=e-1;i>=s;i--){
         if(in[i]<in[e]){
           f=1;
           break;
         }
       }
       if(f==0){
         tr->l=0;
         tr->r=build(s,e-1);
       }else{
         tr->l=build(s,i);
         tr->r=build(i+1,e-1);
       }
       return tr;
}
void go(struct Node *tr){
     if(tr==0)return;
     go(tr->r);
     go(tr->l);
     printf("%d ",tr->num);
}
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&in[i]);
    root=build(0,n-1);
    go(root);
}
