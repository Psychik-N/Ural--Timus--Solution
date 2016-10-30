#include <stdio.h>
#include <stdlib.h>
int y[11000],bh[11000];
int cmp(int *a,int *b){
return y[*a]-y[*b];
}
int main(){
int n,m,i,j,k,yl=0;
scanf("%d %d %d",&n,&m,&k);
for(i=0;i<n;i++)for(j=0;j<m;j++){
bh[n*i+j]=n*i+j;
scanf("%d",&y[n*i+j]);
}
qsort(bh,n*m,4,cmp);
n*=m;
for(i=1;i<n;i++){
if(yl+(y[bh[i]]-y[bh[i-1]])*i>k)break;
yl+=(y[bh[i]]-y[bh[i-1]])*i;
}
printf("%d",y[bh[i-1]]+(k-yl)/i);
}


