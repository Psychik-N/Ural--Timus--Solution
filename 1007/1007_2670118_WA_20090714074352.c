#include <stdio.h>
#include <string.h>
int n,p1[2000],p2[2000],c1[2000],c2[2000];
void r1(char *in){
int t=p2[0]%(n+1);
in[t-1]='0';
}
void r2(char *in){
int i,j,s;
for(i=0;i<n;i++){
s=p2[0]+c2[i];
if(s%(n+1)==0){
for(j=n-1;j>i;j--)
in[j]=in[j-1];
in[i]='0';
return;
}
if((s+i+1)%(n+1)==0){
for(j=n-1;j>i;j--)
in[j]=in[j-1];
in[i]='1';
return;
}
}
}
void r3(char *in){
int i,j,s;
for(i=1;i<=n+1;i++){
s=p2[0]-c2[i]-(in[i-1]-'0')*i;
if(s%(n+1)==0){
for(j=i-1;j<n;j++)
in[j]=in[j+1];
in[n]='\0';
return;
}
}
}
int main(){
char in[2000];
int i;
scanf("%d",&n);
while(1){
scanf("%s",in);
if(feof(stdin))return 0;
for(i=0;i<1100;i++){
c1[i]=c2[i]=0;
in[i]=0;
}
p1[1]=0;
for(i=2;i<=strlen(in)+1;i++){
p1[i]=p1[i-1]+(in[i-2]=='1'?1:0)*(i-1);
c1[i]=c1[i-1]+(in[i-2]=='1'?1:0);
}
p2[strlen(in)]=0;
for(i=strlen(in)-1;i>=0;i--){
p2[i]=p2[i+1]+(in[i]=='1'?1:0)*(i+1);
c2[i]=c2[i+1]+(in[i]=='1'?1:0);
}
if((p2[0]%(n+1))==0&&strlen(in)==n);
else if(strlen(in)==n)r1(in);
else if(strlen(in)==n-1)r2(in);
else if(strlen(in)==n+1)r3(in);
printf("%s\n",in);
}
}
