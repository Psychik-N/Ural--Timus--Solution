#include <stdio.h>
int main(){
    int c[40]={0},s[40]={0},bv=-1,bi,i;
    char in;
    do{
      in=getchar();
      if((in<'0'||in>'9')&&(in<'A'||in>'Z')){
        for(i=2;i<=36;i++){
          if(s[i]==1)c[i]++;
          s[i]=0;
        }
      }else{
        if(in>='0'&&in<='9')in-='0';
        else in=in-'A'+10;
        for(i=2;i<=in;i++){
          if(s[i]==1)c[i]++;
          s[i]=0;
        }
        for(i=in+1;i<=36;i++)s[i]=1;
      }
    }while(in!=-1);
    for(i=2;i<=36;i++){
      if(c[i]>bv){
        bv=c[i];
        bi=i;
      }
    }
    printf("%d %d",bi,bv);
}
