#include <stdio.h>
#include <stdlib.h>
#define H 2500039
struct Item{
       int n1,n2;
       struct Item *next;
}*h1[H]={0},*h2[100000]={0};
int *f[100000],ta[100000],fl[100000];
int main(){
    int n,i,j,q,t,a,b,l,r,m,c=0,tl;
    struct Item *w1,*w2;
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d",&t);
      w1=h1[t%H];
      while(w1!=0){
        if(w1->n1==t){
          w2=malloc(12);
          w2->n1=i;
          w2->next=h2[w1->n2];
          h2[w1->n2]=w2;
          goto out;
        }
        w1=w1->next;
      }
      w1=malloc(12);
      w1->n1=t;
      w1->n2=c++;
      w1->next=h1[t%H];
      h1[t%H]=w1;
      w2=malloc(12);
      w2->n1=i;
      w2->next=h2[w1->n2];
      h2[w1->n2]=w2;
      out:;
    }
    scanf("%d",&q);
    for(i=0;i<c;i++){
      w2=h2[i];
      tl=0;
      while(w2){
        ta[tl++]=w2->n1;
        w2=w2->next;
      }
      f[i]=malloc(4*tl);
      fl[i]=tl;
      for(j=0;j<tl;j++)f[i][j]=ta[tl-1-j];
    }
    for(i=0;i<q;i++){
      scanf("%d%d%d",&a,&b,&t);
      a--;b--;
      w1=h1[t%H];
      while(w1){
        if(w1->n1==t){
          t=w1->n2;
          l=0;
          r=fl[t]-1;
          while(l!=r){
            m=(l+r)/2;
            if(f[t][m]>=a&&f[t][m]<=b){
              printf("1");
              goto nxt;
            }else if(f[t][m]<a)l=m+1;
            else r=m-1;
          }
          if(f[t][l]>=a&&f[t][l]<=b)printf("1");
          else printf("0");
          goto nxt;
        }
        w1=w1->next;
      }
      printf("0");
      nxt:;
    }
}
