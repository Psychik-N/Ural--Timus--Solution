#include <stdio.h>
int bh[101][150010],l[101]={0};
int ms(){
    int s;
    char c;
    do{
         c=getchar();
    }while(c<48||c>57);
    s=c-48;
    while(1){
      c=getchar();
      if(c<48||c>57)return s;
      s=s*10+c-48;
    }
}
void mp(int s){
     char b[10];
     int l=0,i;
     if(s==0){
       putchar(48);
       return;
     }
     while(s){
       b[l]=s%10+48;
       l++;
       s/=10;
     }
     for(i=l-1;i>=0;i--)putchar(b[i]);
}
int main(){
    int n,i,j,a,b;
    n=ms();
    for(i=0;i<n;i++){
      a=ms();
      b=ms();
      bh[b][l[b]]=a;
      l[b]++;
    }
    for(i=100;i>=0;i--){
      for(j=0;j<l[i];j++){
        /*mp(bh[i][j]);
        putchar(' ');
        mp(i);
        putchar('\n');*/printf("%d %d\n",bh[i][j],i);
      }
    }
}
