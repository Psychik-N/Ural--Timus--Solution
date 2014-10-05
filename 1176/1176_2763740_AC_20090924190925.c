#include <stdio.h>
char c[1010][1010]={0};
int n,p[1010]={0},o[35000],ol=0;
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
void mp(int s){
     char b[12];
     int l=0,i,m=0;
     if(s==0){
       putchar(48);
       return;
     }
     if(s<0){
       m=1;
       s=-s;
     }
     while(s){
       b[l]=s%10;
       l++;
       s/=10;
     }
     if(m)putchar('-');
     for(i=l-1;i>=0;i--)putchar(b[i]+'0');
}
void go(int a){
     while(p[a]<n){
       p[a]++;
       if(c[a][p[a]]==1){
         c[a][p[a]]=0;
         go(p[a]);
       }
     }
     o[ol]=a;
     ol++;
}
int main(){
    int i,j,s;
    char in;
    n=ms();
    s=ms();
    for(i=1;i<=n;i++){
      for(j=1;j<=n;j++){
        do{
          in=getchar();
        }while(in!='0'&&in!='1');
        if(in=='0')c[i][j]=1;
      }
    }
    for(i=1;i<=n;i++)c[i][i]=0;
    go(s);
    for(i=ol-1;i>0;i--){
      mp(o[i]);
      putchar(' ');
      mp(o[i-1]);
      putchar('\n');
    }
}
