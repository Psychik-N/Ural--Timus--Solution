#include <stdio.h>
int bh[101][150010],l[101]={0};
int main(){
    int n,i,k,j,a,b,s,il,pl;
    char c,buf[10],ic[2];
    do{
         c=getchar();
    }while(c<48||c>57);
    s=c-48;
    while(1){
      c=getchar();
      if(c<48||c>57)break;
