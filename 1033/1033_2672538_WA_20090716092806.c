#include <stdio.h>
#include <string.h>
char in[40][40]={0},ch[40];
int t=0,n,r=0;
void v(int a,int b){
in[a][b]='*';
if(a==n&&b==n)r=1;
if(in[a-1][b]=='.')v(a-1,b);
if(in[a-1][b]=='#')t++;
if(in[a][b-1]=='.')v(a,b-1);
if(in[a][b-1]=='#')t++;
if(in[a+1][b]=='.')v(a+1,b);
if(in[a+1][b]=='#')t++;
if(in[a-1][b]=='.')v(a,b+1);
if(in[a-1][b]=='#')t++;
}
int main(){
int i,j;
scanf("%d",&n);
for(i=1;i<=n;i++){
scanf("%s",ch);
in[i][0]='#';
strcat(in[i],ch);
strcat(in[i],"#");
}
for(i=0;i<=n;i++)
in[0][i]=in[n+1][i]='#';
v(1,1);
if(r==0)v(n,n);
printf("%d",t*9-36);
}
