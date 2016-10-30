#include <stdio.h>
char in[40][40];
int t=0,n,r=0;
void v(int a,int b){
in[a][b]='*';
if(a==n-1&&b==n-1)r=1;
if(a>0){
if(in[a-1][b]=='.')v(a-1,b);
if(in[a-1][b]=='#')t++;
}
if(b>0){
if(in[a][b-1]=='.')v(a,b-1);
if(in[a][b-1]=='#')t++;
}
if(a<n-1){
if(in[a+1][b]=='.')v(a+1,b);
if(in[a+1][b]=='#')t++;
}
if(b<n-1){
if(in[a-1][b]=='.')v(a,b+1);
if(in[a-1][b]=='#')t++;
}
}
int main(){
int i;
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%s",in[i]);
v(0,0);
if(r==0)v(n-1,n-1);
printf("%d",t*9);
}
