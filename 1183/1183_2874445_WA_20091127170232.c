#include <stdio.h>
#include <string.h>
int f[110][110]={0},l;
char c[110];
int min(int a,int b){
    if(a<b)return a;
    return b;
}
int go(int s,int e){
    int i,bv=2000000000;
    if(f[s][e])return f[s][e];
    if(s==e)return 1;
    if(s>e)return 0;
    if(c[s]==c[e])bv=min(bv,go(s+1,e-1));
    if(c[s]=='('||c[s]=='[')bv=min(bv,go(s+1,e)+1);
    if(c[e]==')'||c[e]==']')bv=min(bv,go(s,e-1)+1);
    for(i=s;i<e;i++)bv=min(bv,go(s,i)+go(i+1,e));
    return f[s][e]=bv;
}
int main(){
    scanf("%s",c);
    l=strlen(c);
    printf("%d\n",go(0,l-1));
}
