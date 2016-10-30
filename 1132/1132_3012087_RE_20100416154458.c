#include <stdio.h>
#include <math.h>
#include <string.h>
short x[360][16500];
int prime[5000]={2,3},bt[50000]={0,0,0,1},pl=2,al[100010],nl[100010],ol[100010]={0};
int main(){
    int i,j,k,a,n,lmt,base,ii;
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
    for(base=0;base<3600;base+=360){
      memset(x,360*16500*2,0);
      for(i=0;i<360;i++){
        ii=base+i;
        lmt=prime[ii]/2;
        for(j=0;j<=lmt;j++){
          k=j*j%prime[ii];
          x[i][k]=j+1;
        }
      }
      for(j=0;j<k;j++){
        if(bt[nl[j]]<base||bt[nl[j]]>=base+360)continue;
        n=bt[nl[j]]-base;
        a=al[j];
        if(x[bt[n]][a]==0)ol[j]=-1;
        else ol[j]=x[bt[n]][a]-1;
      }
    }
    for(i=0;i<k;j++){
      if(ol[j]==-1)printf("No root\n");
      else if(nl[i]-ol[j]==ol[j])printf("%d\n",ol[j]);
      else printf("%d %d\n",ol[j],nl[j]-ol[j]);
    }
}

