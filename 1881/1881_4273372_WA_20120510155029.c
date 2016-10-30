#include <stdio.h>
#include <string.h>
char s[110];
int main(){
int h,w,n,i,r=0,y=0,l,a=1;
scanf("%d%d%d\n",&h,&w,&n);
for(i=0;i<n;i++){
scanf("%s\n",s);
l=strlen(s);
if(r+l<=w)r+=l;
else{
y++;
r=l;
if(y==h){a++;y=0;}
}
}
if(y==0&&r==0)a--;
printf("%d\n",a);
}
