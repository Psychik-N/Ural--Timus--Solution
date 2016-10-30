#include <stdio.h>
int head[110],m[110][110];
char o[110][110];
void zip(int a){
int t,w=a,h;
while(head[w]!=w)w=head[w];
h=w;
w=a;
while(w!=h){
t=head[w];
head[w]=h;
w=t;
}
}
void link(int a,int b){
head[head[a]]=b;
}
int find(int a){
zip(a);
return head[a];
}
int main(){
int n,d,a,i,j,ca=0,cd=0;
char in[110];
for(i=0;i<110;i++)h[i]=i;
for(i=0;i<110;i++)for(j=0;j<110;j++)o[i][j]='0';
scanf("%d %d %d",&n,&d,&a);
for(i=0;i<n;i++){
scanf("%s",in);
for(j=0;j<n;j++)m[i][j]=in[j]-'0';
}
for(i=0;i<n;i++)for(j=i+1;j<n;j++)
if(m[i][j]&&find(i)!=find(j)){
link(i,j);
cd++;
o[i][j]=o[j][i]='d';
}
for(i=0;i<n;i++)for(j=i+1;j<n;j++)
if(m[i][j]==0&&find(i)!=find(j)){
link(i,j);
ca++;
o[i][j]=o[j][i]='a';
}
printf("%I64d\n",(long long)ca*a+(long long)cd*d);
for(i=0;i<n;i++){
for(j=0;j<n;j++)printf("%c",o[i][j]);
printf("\n");
}
}


