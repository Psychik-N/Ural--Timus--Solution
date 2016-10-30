#include <stdio.h>
#include <string.h>
int main(){
char in[100];
int l,i,c[26]={0},bv=-1,bi;
gets(in);
l=strlen(in);
for(i=0;i<l;i++)c[in[i]-'a']++;
for(i=0;i<l;i++)if(c[i]>bv){
bv=c[i];
bi=i;
}
putchar((char)bi+'a');
}
