#include <stdio.h>
int ms(){
    char c;
    int s;
    do{
      c=getchar();
    }while(c<'0'||c>'9');
    s=c-'0';
    while(1){
      c=getchar();
      if(c<'0'||c>'9')break;
      s=s*10+c-'0';
    }
    return s;
}
int main(){
    int n,k,v[25010],i,j,p,c,s;
    char m[25010];
    n=ms();
    for(i=0;i<n;i++){
      k=ms();
      c=0;
      s=1;
      memset(m,0,25005);
      for(j=1;j<=k;j++){
        v[j]=ms();
        if(v[j]==0)c++;
      }
      if(c!=1){
        puts("NO");
        goto nxt;
      }
      for(j=1;j<=k;j++){
        if(m[j]!=0||v[j]==0)continue;
        p=j;
        while(1){
          if(p==0)break;
          if(m[p]==s){
            puts("NO");
            goto nxt;
          }
          m[p]=s;
          p=v[p];
        }
        s++;
      }
      puts("YES");
      nxt:;
    }
}
