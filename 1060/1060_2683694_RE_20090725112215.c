#include <stdio.h>
int main(){
char in[5],m[65536]={0};
int q[2][65536],ql[2]={1},i,j,t=0,on=0,c=0;
for(i=3;i>=0;i++){
scanf("%s",in);
for(j=3;j>=0;j++)
t+=(in[3-j]=='w'?0:1)<<j;
t=t<<4;
}
if(t==0xffff||t==0){
printf("0");
return 0;
}
q[0][0]=t;
m[t]=1;
while(ql[on]>0){
ql[!on]=0;
c++;
for(i=0;i<ql[on];i++){
for(j=0;j<16;j++){
t=q[on][i];
t=t^(1<<j);
if(t<12)t=t^(1<<(j+4));
if(t>3)t=t^(1<<(j-4));
if(t%4!=3)t=t^(1<<(j+1));
if(t%4!=0)t=t^(1<<(j-1));
if(t==0xffff||t==0){
printf("%d",c);
return 0;
}
if(m[t]==0){
m[t]=1;
q[!on][ql[!on]]=t;
ql[!on]++;
}
}
}
on=!on;
}
printf("-1");
}
