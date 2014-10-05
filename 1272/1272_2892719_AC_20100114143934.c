#include <stdio.h>
#include <stdlib.h>
struct Edge{
       int num;
       struct Edge* next;
};
int *queue[2],on=0,len[2],n,m,v1,v2,*mark,*ob,oblen;
struct Edge **edg;
int main(){
    int i,j,i1,k,ans=0;
    struct Edge *temp;
    scanf("%d %d %d",&n,&m,&k);
    edg=malloc(sizeof(struct Edge*)*n);
    mark=malloc(sizeof(int)*n);
    ob=malloc(sizeof(int)*n);
    for(i=0;i<2;i++)
                    queue[i]=malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
                     edg[i]=NULL;
                     mark[i]=0;
    }
    for(i=0;i<m;i++){
                     scanf("%d %d",&v1,&v2);
                     v1--;v2--;
                     temp=malloc(sizeof(struct Edge));
                     temp->num=v2;
                     temp->next=edg[v1];
                     edg[v1]=temp;
                     temp=malloc(sizeof(struct Edge));
                     temp->num=v1;
                     temp->next=edg[v2];
                     edg[v2]=temp;
    }
    for(i1=0;i1<n;i1++){
      if(mark[i1])continue;
      on=0;
      queue[0][0]=i1;
      len[0]=1;
      while(len[on]!=0){
        on=!on;
        len[on]=0;
        if(edg[queue[!on][0]]==NULL){
                                     oblen=1;
                                     ob[0]=i1;
        }
        for(i=0;i<len[!on];i++){
          temp=edg[queue[!on][i]];
          while(temp!=NULL){
            if(mark[temp->num]==0){
              queue[on][len[on]]=temp->num;
              len[on]++;
              mark[temp->num]=1;
            }
            temp=temp->next;
          }
        }
      }
      ans++;
    }
    printf("%d\n",ans-1);
}

