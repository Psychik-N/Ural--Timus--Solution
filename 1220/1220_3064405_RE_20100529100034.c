#include <stdio.h>
int p=0,d[100010],h[1010]={0};
unsigned short x[100010]={0},x2[10000]={0};
int main(){
int n,a,b,t,i;
char c[10];
scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%s",c);
if(c[1]=='U'){
scanf("%d%d",&a,&d[p]);
t=h[a];
h[a]=p;
x[p]=(unsigned short)(t&0xffff);
x2[p/16]=x2[p/16]|(short)(((t&0x10000)>>16)<<(p%16));
p++;
}else{
scanf("%d",&a);
printf("%d\n",d[h[a]]);
t=h[a];
h[a]=((int)x[t])|((int)(x2[t/16]&(1<<(t%16)))<<16);
}
}
}
