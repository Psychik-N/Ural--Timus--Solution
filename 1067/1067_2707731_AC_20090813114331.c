#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node{
       char n[10];
       struct Node *fc;
       struct Node *nb;
};
void go(struct Node *nn,int lv){
     struct Node *w=nn->nb;
     int i;
     while(w!=0){
       for(i=0;i<lv;i++)
         putc(' ',stdout);
       puts(w->n);
       go(w->fc,lv+1);
       w=w->nb;
     }
}
int main(){
    int n,i,j,l,bl,cr;
    char in[100],buf[9];
    struct Node *root,*b,*t,*w;
    root=malloc(sizeof(struct Node));
    strcpy(root->n,".");
    root->fc=root->nb=0;
    scanf("%d\n",&n);
    for(i=0;i<n;i++){
      gets(in);
      strcat(in,"\\");
      l=strlen(in);
      bl=0;
      b=root;
      w=root->nb;
      for(j=0;j<l;j++){
        if(in[j]!='\\'){
          buf[bl]=in[j];
          bl++;
        }else{
          buf[bl]=0;
          while(w!=0){
            cr=strcmp(buf,w->n);
            if(cr<0)
              break;
            else if(cr==0){
              b=w->fc;
              w=w->fc->nb;
              goto nxt;
            }else{
              b=w;
              w=w->nb;
            }
          }
          t=malloc(sizeof(struct Node));
          strcpy(t->n,buf);
          t->fc=malloc(sizeof(struct Node));
          strcpy(t->fc->n,".");
          t->fc->fc=t->fc->nb=0;
          t->nb=w;
          b->nb=t;
          w=t->fc->nb;
          b=t->fc;
          nxt:
          bl=0;
        }
      }
    }
    go(root,0);
}
