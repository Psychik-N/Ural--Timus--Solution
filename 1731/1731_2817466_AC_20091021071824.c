#include <stdio.h>
int main(){
int i,m,n;
scanf("%d%d",&m,&n);
for(i=1;i<=m;i++)printf("%d ",i);
printf("\n");
for(i=1;i<=n;i++)printf("%d ",(i+1)*m);
}
