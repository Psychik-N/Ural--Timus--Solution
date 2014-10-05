#include <stdio.h>
#include <string.h>
int main(){
char in[1000];
int i,l,j,c,bv=2000000000;
scanf("%s",in);
l=strlen(in);
for(i=0;i<=l-6;i++){
c=0;
if(in[i+0]=='S');
else if(in[i+0]=='s')c++;
else if(isupper(in[i+0]))c++;
else c+=2;
if(in[i+1]=='a');
else if(in[i+1]=='A')c++;
else if(islower(in[i+1]))c++;
else c+=2;
if(in[i+2]=='n');
else if(in[i+2]=='N')c++;
else if(islower(in[i+2]))c++;
else c+=2;
if(in[i+3]=='d');
else if(in[i+3]=='D')c++;
else if(islower(in[i+3]))c++;
else c+=2;
if(in[i+4]=='r');
else if(in[i+4]=='R')c++;
else if(islower(in[i+4]))c++;
else c+=2;
if(in[i+5]=='o');
else if(in[i+5]=='O')c++;
else if(islower(in[i+5]))c++;
else c+=2;
if(c<bv)bv=c;
}
printf("%d",bv*5);
}
