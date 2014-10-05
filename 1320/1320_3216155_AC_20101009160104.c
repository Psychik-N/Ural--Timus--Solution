#include <stdio.h>
char c[1100][1100]={0},m[1100]={0};
int n=1010,s=0;
void go(int p){
int i;
for(i=0;i<n;i++)if(c[p][i]){
s++;
c[p][i]=c[i][p]=0;
if(m[i]==0){
m[i]=1;
go(i);
}
}
}
int main(){
int a,b,i;
while(scanf("%d%d",&a,&b)!=EOF)c[a][b]=c[b][a]=1;
for(i=0;i<n;i++){
if(m[i]==0){
m[i]=1;
go(i);
}
if(s&1){
printf("0");
return 0;
}
s=0;
}
printf("1");
}
