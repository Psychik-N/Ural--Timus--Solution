#include <stdio.h>
#include <string.h>
char in[10010];
int main(){
int i,j,l;
gets(in);
l=strlen(in);
if(l==1){putchar(in[0]);putchar(in[0]);return 0;}
for(i=(l+1)/2;i<l;i++){
for(j=i+1;j<l;j++)if(in[j]!=in[i+i-j])goto nxt;
for(j=0;j<=i;j++)putchar(in[j]);
for(j=i-1;j>=0;j--)putchar(in[j]);
return 0;
nxt:;
}
}
