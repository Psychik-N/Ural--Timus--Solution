#include <stdio.h>
int main(){
    int o[100][2],ol=0,n,in[100][2],p[100][2],le=-1000,i,j,bv,bi,t,a,b,pv[100];
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d%d",&a,&b);
      if(a>b){
        t=a;
        a=b;
        b=t;
      }
      in[i][0]=a;
      in[i][1]=b;
      pv[i]=b*1000+a;
    }
    for(i=0;i<n;i++){
      bv=2000000000;
      for(j=0;j<n;j++){
        if(pv[j]<bv){
          bv=pv[j];
          bi=j;
        }
      }
      p[i][0]=in[bi][0];
      p[i][1]=in[bi][1];
      pv[bi]=2000000000;
    }
    for(i=0;i<n;i++){
      if(p[i][0]>=le){
        le=p[i][1];
        o[ol][0]=p[i][0];
        o[ol][1]=p[i][1];
        ol++;
      }
    }
    printf("%d\n",ol);
    for(i=0;i<ol;i++)
      printf("%d %d\n",o[i][0],o[i][1]);
}
