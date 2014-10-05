#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int main(){
    int n,p,i,o[1200],fp=20000,zp=20000;
    scanf("%d%d",&n,&p);
    for(i=1;i<=n;i++)scanf("%d",&o[i]);
    o[0]=-100000;
    o[n+1]=100000;
    qsort(o,n+1,4,cmp);
    for(i=0;i<=n;i++)if(o[i]<0&&o[i+1]>0){
      fp=i;
      zp=i+1;
    }
    if(p>0){
      if(o[zp]<p)goto fail;
      printf("%d %d\n",p,-2*o[fp]+p);
    }else if(p==0)printf("0 0\n");
    else{
      if(o[fp]>p)goto fail;
      printf("%d %d\n",2*o[zp]-p,-p);
    }
    return 0;
    fail:printf("Impossible\n");
}
