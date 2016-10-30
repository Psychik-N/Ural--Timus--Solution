#include <stdio.h>
int z[110][110]={0};
int main(){
int n,m,a,b,c,d,i,s=0,x=1,y=1,sc=0;
scanf("%d%d%d%d%d%d",&n,&m,&a,&b,&c,&d);
for(i=0;i<110;i++)z[0][i]=z[n+1][i]=z[i][0]=z[i][m+1]=1;
while(sc<n*m){
sc++;
z[x][y]=sc;
if(s==0)&&z[x][y+1]!=0)s++;
if(s==1)&&z[x+1][y]!=0)s++;
if(s==2)&&z[x][y-1]!=0)s++;
if(s==3)&&z[x-1][y]!=0)s=0;
if(s==0)y++;
if(s==1)x++;
if(s==2)y--;
if(s==3)x--;
}
sc=z[a][b]-z[c][d];
if(sc<0)sc=-sc;
printf("%d",sc);
}
