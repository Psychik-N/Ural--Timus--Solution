#include <stdio.h>
int main(){
    int a[66001],b[66001],i,j,f[66001],n,s,e,y,nv=2500,o[66001][3],ol=0;
    for(i=0;i<66001;i++)
      a[i]=b[i]=f[i]=2500;
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d %d %d",&s,&e,&y);
      s+=33000;
      e+=33000;
      for(j=s;j<e;j++)
        a[j]=y;
    }
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d %d %d",&s,&e,&y);
      s+=33000;
      e+=33000;
      for(j=s;j<e;j++)
        b[j]=y;
    }
    for(i=0;i<66001;i++)
      if(a[i]!=2500&&b[i]==2500)
        f[i]=a[i];
    for(i=0;i<66001;i++){
      if(nv==f[i])continue;
      if(nv!=2500){
        o[ol][0]=s;
        o[ol][1]=i;
        o[ol][2]=nv;
        ol++;
      }
      nv=f[i];
      s=i;
    }
    printf("%d",ol);
    for(i=0;i<ol;i++)
      printf(" %d %d %d",o[i][0]-33000,o[i][1]-33000,o[i][2]);
}
