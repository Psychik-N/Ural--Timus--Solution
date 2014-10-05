#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int t(char *c){
int l=strlen(c);
c[l-3]=c[l-2];
c[l-2]=c[l-1];
c[l-1]=0;
return atoi(c);
}
int main(){
int i,n,a[5000],c[5000],v1=-200000,v2=200000;
char in[20];
scanf("%d",&n);
scanf("%s",in);
a[0]=t(in);
scanf("%s",in);
a[n+2]=t(in);
for(i=1;i<=n;i++){
scanf("%s",in);
c[i]=t(in);
}
while(1){
a[1]=(v1+v2)/2;
for(i=2;i<=n+1;i++)
a[i]=2*a[i-1]-a[i-2]+2*c[i-1];
if(a[n+1]<a[n+2])v1=a[1]+1;
else if(a[n+1]>a[n+2])v2=a[1]-1;
else{
printf("%d.%d%d",a[1]/100,(a[1]/10+1000000)%10,(a[1]+1000000)%10);
return 0;
}
}
}
