#define n 6
#include <stdio.h>
#include <memory.h>
char m[n][n];
int main(){
int bit,p1,i,j,k,tc;
for(bit=0;bit<0x8000;bit++){
memset(m,0,36);
p1=0;
for(i=0;i<n;i++)for(j=i+1;j<n;j++){
m[i][j]=m[j][i]=(char)((bit>>p1)&1);
p1++;
}
for(i=0;i<n;i++){
for(j=0;j<n;j++)if(i!=j&&m[i][j]==0)goto n1;
goto nb;
n1:;
}
for(i=0;i<n;i++)for(j=0;j<n;j++)for(k=0;k<n;k++)if(m[i][j]&&m[j][k]&&m[i][k])goto nb;
for(i=0;i<n;i++)for(j=0;j<n;j++)if(i!=j&&m[i][j]==0){
tc=0;
for(k=0;k<6;k++)if(m[i][k]&m[j][k])tc++;
if(tc!=1)goto nb;
}
for(i=0;i<n;i++)for(j=0;j<n;j++)printf("%c",m[i][j]+48);
while(1);
return 0;
nb:;
}
}
