#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int v[800][800];
int main(){
int n,m,i,j;
srand((int)time(0));
scanf("%d%d",&n,&m);
for(i=0;i<n;i++)for(j=0;j<m;j++)scanf("%d",&v[i][j]);
for(i=0;i<n;i++){
for(j=0;j<m;j++){
if(rand()%256<v[i][j])printf("255 ");
else printf("0 ");
}
printf("\n");
}
}
