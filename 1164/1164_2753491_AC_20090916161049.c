#include <stdio.h>
int main(){
int n,m,p,i,j,l,c[26]={0};
char in[100];
scanf("%d%d%d\n",&n,&m,&p);
for(i=0;i<n;i++){
gets(in);
for(j=0;j<m;j++)c[in[j]-'A']++;
}
for(i=0;i<p;i++){
gets(in);
l=strlen(in);
for(j=0;j<l;j++)c[in[j]-'A']--;
}
for(i=0;i<26;i++)for(j=0;j<c[i];j++)putchar(i+'A');
}
