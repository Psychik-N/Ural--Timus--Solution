#include <stdio.h>
#include <string.h>
char s[250][50];
int main(){
int y,n,i,j,c=0,l,q;
char in[50],bk[50];
scanf("%d%d%d",&y,&n,&q);
for(i=0;i<n;i++){
scanf("%s",in);
strcpy(bk,in);
for(j=strlen(in)-1;j>=0;j--){
if(in[j]=='#')in[j]=in[j-1]=0;
if(in[j]>='A'&&in[j]<='Z')in[j]+='a'-'Z';
}
for(j=0;j<c;j++)if(strcmp(in,s[j])==0)goto nxt;
strcpy(s[c],in);
if(++c==q+1)break;
nxt:;
}
puts(bk);
}
