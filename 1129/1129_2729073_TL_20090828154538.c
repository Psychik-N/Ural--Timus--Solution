#include <stdio.h>
int main(){
char c[101][101]={0},m[101][101]={0},o[101][101];
int n,k,i,j,p=1,b=1,f=0,s=0,x=0,y=0;
scanf("%d",&n);
for(i=1;i<=n;i++){
scanf("%d",&k);
for(j=0;j<k;j++){
scanf("%d",&p);
c[p][i]=c[i][p]=1;
s++;
}
}
go:
for(i=1;i<=n;i++)
if(c[p][i]&(!m[p][i])){
m[p][i]=m[i][p]=1;
if(x){
o[p][i]='Y';
o[i][p]='G';
}else{
o[p][i]='G';
o[i][p]='Y';
}
y=1;
p=i;
f++;
f++;
goto go;
}
if(f!=s){
if(y)b++;
y=0;
p=b;
x=!x;
goto go;
}
for(i=1;i<=n;i++){
for(j=1;j<=n;j++)
if(c[i][j])
printf("%c ",o[i][j]);
printf("\n");
}
}
