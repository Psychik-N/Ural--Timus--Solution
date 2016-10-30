#include <stdio.h>
int ms(){
    int s=0;
    char c,m=0;
    do{
      c=getchar();
    }while((c!='-')&&(c<48||c>57));
    if(c=='-')m=1;
    else s=c-48;
    while(1){
      c=getchar();
      if(c<48||c>57)break;
      s=s*10+c-48;
    }
    if(m)return -s;
    return s;
}
int main(){
    int n,i,y,s[10010]={0},lst=1,tot=0;
    char in;
    n=ms();
    for(i=0;i<n;i++){
      do{
        in=getchar();
      }while(in!=' '&&in!=13);
      y=ms();
      if(y==1)s[i]=ms();
    }
    for(i=n-1;i>=0;i--){
      if(s[i]!=0)lst=s[i];
      tot+=lst;
      if(tot>10000){
        puts("NO");
        return 0;
      }
    }
    puts("YES");
}
