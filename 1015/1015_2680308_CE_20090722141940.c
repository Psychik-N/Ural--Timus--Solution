#include <stdio.h>
int trans[6][6]={{4,2,0,3,1,5},{2,4,1,3,0,5},{0,1,4,5,2,3},{0,1,3,4,5,2},{0,1,2,3,4,5},{0,1,5,2,3,4}},h2seq[4]={0,3,1,5};
int hash1[60],hash2[60],types=0,belong[100001];
int main(){
    int now[6],tred[6],n,i,j,k,h1,h2,mi,mv,found;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
      for(j=0;j<6;j++)
        scanf("%d",&now[j]);
      for(j=0;j<6;j++){
        if(now[j]==1){
          for(k=0;k<6;k++)
            tred[trans[j][k]]=now[k];
          h1=tred[2];
          break;
        }
      }
      mv=7;
      for(j=0;j<4;j++){
        if(tred[h2seq[j]]<mv){
          mv=tred[h2seq[j]];
          mi=j;
        }
      }
      h2=mv*100+tred[h2seq[(mi+1)%4]]*10+tred[h2seq[(mi+2)%4]];
      found=0;
      for(j=0;j<types;j++){
        if(h1==hash1[j]&&h2==hash2[j]){
          belong[i]=j;
          found=1;
          break;
        }
      }
      if(found==0){
        hash1[types]=h1;
        hash2[types]=h2;
        belong[i]=types;
        types++;
      }
    }
    int tt;
    printf("%d\n",types);
    for(i=0;i<types;i++){
      tt=-1;
      for(j=1;j<=n;j++){
        if(tt==-1&&belong[j]!=250)
          tt=belong[j];
        if(belong[j]==tt){
          printf("%d ",j);
          belong[j]=250;
        }
      }
      printf("\n");
    }

}
