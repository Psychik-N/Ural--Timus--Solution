#include <stdio.h>
int md[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int tr(char *s){
int a,b,c,r=0,i;
a=(s[6]-48)*1000+(int)(s[7]-48)*100+(s[8]-48)*10+s[9]-48;
b=(s[3]-48)*10+s[4]-48;
c=(s[0]-48)*10+s[1]-48;
for(i=1800;i<a;i++){
r+=365;
if(i%400==0||(i%4==0&&i%100!=0))r++;
}
for(i=1;i<b;i++){
r+=md[i];
if(a%400==0||(a%4==0&&a%100!=0))if(i==2)r++;
}
r+=c;
return r;
}
int main(){
int n,i,bi,bv=-1,b2,t1,t2;
char in[20];
scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%s",in);
t1=tr(in);
scanf("%s",in);
scanf("%s",in);
t2=tr(in);
if(t2-t1>bv||(t2-t1==bv&&t2<b2){
bv=t2-t1;
b2=t2;
bi=i;
}
}
printf("%d",i+1);
}



