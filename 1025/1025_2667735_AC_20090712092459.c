#include <stdio.h>
int main(){
int k,rs[101],mi,mv,o=0,i,j;
scanf("%d",&k);
for(i=0;i<k;i++)scanf("%d",&rs[i]);
for(i=0;i<=k/2;i++){
mv=2000000000;
for(j=0;j<k;j++){
if(rs[j]<mv){
mv=rs[j];
mi=j;
}
}
o+=mv/2+1;
rs[mi]=2000000000;
}
printf("%d",o);
}
