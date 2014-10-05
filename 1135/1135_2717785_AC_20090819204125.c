#include <stdio.h>
int main(){
int n,i,l=0,r=0;
char c;
scanf("%d",&n);
while(scanf("%c",&c)!=EOF){
if(c=='>')r++;
if(c=='<')l+=r;
}
printf("%d",l);
}
