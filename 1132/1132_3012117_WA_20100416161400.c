#include <stdio.h>
#include <math.h>
#include <string.h>
short x[200][33000];
int prime[5000]={2,3},bt[50000]={0,0,0,1},pl=2,al[100010],nl[100010],ol[100010]={0};
int main(){
    int i,j,k,a,n,lmt,base,ii,tk;
    for(i=4;i<32768;i++){
      lmt=(int)(sqrt(i)+0.99999999);
      for(j=0;j<pl;j++){
        if(i%prime[j]==0)goto nxt;
        if(prime[j]>=lmt){
          prime[pl]=i;
          bt[i]=pl++;
          goto nxt;
        }
      }
      nxt:;
    }
    scanf("%d",&k);
    for(i=0;i<k;i++){
      scanf("%d%d",&al[i],&nl[i]);
      al[i]%=nl[i];
    }
    for(base=0;base<3600;base+=200){
      memset(x,200*33500*2,0);
      for(i=0;i<200;i++){
        ii=base+i;
        if(ii>=pl)break;
        lmt=prime[ii]/2;
        for(j=0;j<=lmt;j++){
          tk=j*j%prime[ii];
          x[i][tk]=j+1;
        }
      }
      for(j=0;j<k;j++){
        if(bt[nl[j]]<base||bt[nl[j]]>=base+200)continue;
        n=bt[nl[j]]-base;
        a=al[j];
        if(x[n][a]==0)ol[j]=-1;
        else ol[j]=x[n][a]-1;
      }
    }
    for(i=0;i<k;i++){
      if(ol[i]==-1)printf("No root\n");
      else if(nl[i]-ol[i]==ol[i])printf("%d\n",ol[i]);
      else printf("%d %d\n",ol[i],nl[i]-ol[i]);
    }
}


