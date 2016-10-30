#include <stdio.h>
int main(){
int k,i,j,a,n,c;
scanf("%d",&k);
for(i=0;i<k;i++){
scanf("%d%d",&a,&n);
c=0;
for(j=1;j<n-1;j++)if(j*j%n==a){
printf("%d ",j);
c++;
}
if(c==0)printf("No root");
printf("\n");
}
}
