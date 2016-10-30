#include <stdio.h>
int main(){
char c[101][101]={0},m[101][101]={0},o[101][101];
int n,k,i,j,p;
scanf("%d",&n);
for(i=1;i<=n;i++){
scanf("%d",&k);
for(j=0;j<k;j++){
scanf("%d",&p);
c[p][i]=c[i][p]=1;
}
}
start:
p=1;
go:
for(i=1;i<=n;i++)
if(c[p][i]&(!m[p][i]){
m[p][i]=m[i][p]=1;
o[p][i]='Y';
o[i][p]='G';
p=i;
goto go;
}
if(p!=1)goto start;
for(i=1;i<=n;i++){
for(j=1;j<=n;j++)
if(c[i][j])
printf("%c ",o[i][j]);
printf("\n");
}
}
