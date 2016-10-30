#include <stdio.h>
#include <math.h>
short x[3600][16500]={0};
int prime[5000]={2,3},bt[50000]={0,0,0,1},pl=2;
int main(){
    int i,j,k,a,n,lmt;
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
    for(i=0;i<pl;i++){
      lmt=prime[i]/2;
      for(j=0;j<=lmt;j++){
        k=j*j%prime[i];
        x[i][k]=j+1;
      }
    }
    scanf("%d",&k);
    for(i=0;i<k;i++){
      scanf("%d%d",&a,&n);
      if(x[bt[n]][a]==0)printf("No root\n");
      else{
        if(x[bt[n]][a]-1!=n-(x[bt[n]][a]-1))printf("%d %d\n",(int)x[bt[n]][a]-1,n-(int)(x[bt[n]][a]-1));
        else printf("%d\n",(int)x[bt[n]][a]-1);
      }
    }
}
