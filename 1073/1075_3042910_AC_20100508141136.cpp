#include <stdio.h>
#pragma comment(linker,"/STACK:16777216")
int f[60010]={0,1};
int min(int a,int b){
    if(a<b)return a;
    return b;
}
int go(int a){
    int i=1,r=100000;
    if(f[a]!=0||a==0)return f[a];
    while(i*i<=a){
      r=min(r,1+go(a-i*i));
      i++;
    }
    return f[a]=r;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",go(n));
}
