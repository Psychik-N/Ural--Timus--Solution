#include <stdio.h>
#include <string.h>
int main(){
char in[100];
int l,i,c[256]={0},bv=-1,bi;
gets(in);
l=strlen(in);
for(i=0;i<l;i++)c[in[i]]++;
for(i=0;i<256;i++)if(c[i]>bv){
bv=c[i];
bi=i;
}
putchar((char)bi);
}
