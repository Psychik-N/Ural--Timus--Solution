#include <stdio.h>
#include <string.h>
struct Edge{
       int to;
       struct Edge *next;
};
int tran(char *in){
    int l=strlen(in),i=0,t=0,o=0;
    for(i=0;i<l;i++){
      if(in[i]=='.'){
        o=(o<<8)+t;
        t=0;
      }else{
        t=t*10+(in[i]-'0');
      }
    }
    return o;
}
int main(){
    int tz[100][5]={0},n,rk,fl[100],h,i,j,k,on=0,ql[2],q[2][100],from[100]={0},s,e;
    char i1[20],i2[20];
    struct Edge *edg[100]={0},*t,*w;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
      scanf("%d",&rk);
      for(j=0;j<rk;j++){
        scanf("%s %s",i1,i2);
        strcat(i1,".");
        strcat(i2,".");
        tz[i][j]=tran(i1)&tran(i2);
      }
      fl[i]=rk;
    }
    for(i=1;i<n;i++){
      for(j=i+1;j<=n;j++){
        for(h=0;h<fl[i];h++){
          for(k=0;k<fl[j];k++){
            if(tz[i][h]==tz[j][k]){
              t=malloc(sizeof(struct Edge));
              t->to=j;
              t->next=edg[i];
              edg[i]=t;
              t=malloc(sizeof(struct Edge));
              t->to=i;
              t->next=edg[j];
              edg[j]=t;
            }
          }
        }
      }
    }
    scanf("%d %d",&s,&e);
    ql[0]=1;
    q[0][0]=s;
    while(ql[on]>0){
      ql[!on]=0;
      for(i=0;i<ql[on];i++){
        w=edg[q[on][i]];
        while(w!=0){
          if(from[w->to]==0){
            from[w->to]=q[on][i];
            q[!on][ql[!on]]=w->to;
            ql[!on]++;
          }
          w=w->next;
        }
      }
      on=!on;
    }
    if(from[e]==0){
      printf("No");
      return 0;
    }
    ql[0]=0;
    i=e;
    while(i!=s){
      q[0][ql[0]]=i;
      ql[0]++;
      i=from[i];
    }
    printf("Yes\n");
    printf("%d ",s);
    for(i=ql[0]-1;i>=0;i--)
      printf("%d ",q[0][i]);
}
