#include <stdio.h>
#include <string.h>
char ss[20],m[4][4],b[4][5];
int sl;
int go(int x,int y,int p){
if(m[x][y])return 0;
if(ss[p]!=b[x][y])return 0;
if(p==sl-1)return 1;
m[x][y]=1;
if(x>0&&go(x-1,y,p+1))return 1;
if(x<3&&go(x+1,y,p+1))return 1;
if(y>0&&go(x,y-1,p+1))return 1;
if(y<3&&go(x,y+1,p+1))return 1;
return 0;
}
int main(){
int n,i,j;
for(i=0;i<4;i++)scanf("%s",b[i]);
scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%s",ss);
sl=strlen(ss);
for(j=0;j<16;j++){
memset(m,0,16);
if(go(j/4,j%4,0)){
printf("%s: YES\n",ss);
goto nxt;
}
}
printf("%s: NO\n",ss);
nxt:;
}
}
