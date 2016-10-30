#include <stdio.h>
int j(char c){
if(c=='A'||c=='O'||c=='P'||c=='R')return 1;
if(c=='B'||c=='M'||c=='S')return 2;
return 3;
}
int abs(int a){
if(a>=0)return a;
return -a;
}
int main(){
int p=1,s=0,n,i,r;
char b[20];
scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%s",b);
r=j(b[0]);
s+=abs(p-r);
p=r;
}
printf("%d\n",s);
return 0;
}
