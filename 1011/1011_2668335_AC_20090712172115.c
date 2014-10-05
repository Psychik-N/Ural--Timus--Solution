#include <stdio.h>
#include <string.h>
int main(){
    long i=2,sj,xj,p=0,q=0;
    char in[10],find;
    scanf("%s",in);
    find=0;
    for(i=0;i<strlen(in);i++){
      if(in[i]=='.'){
        find=1;
        break;
      }
      p=p*10+in[i]-'0';
    }
    p*=100;
    if(find){
      if(strlen(in)-i>=2)
        p+=(in[i+1]-'0')*10;
      if(strlen(in)-i==3)
        p+=in[i+2]-'0';
    }
    scanf("%s",in);
    find=0;
    for(i=0;i<strlen(in);i++){
      if(in[i]=='.'){
        find=1;
        break;
      }
      q=q*10+in[i]-'0';
    }
    q*=100;
    if(find){
      if(strlen(in)-i>=2)
        q+=(in[i+1]-'0')*10;
      if(strlen(in)-i==3)
        q+=in[i+2]-'0';
    }
    while(1){
      xj=i*p;
      sj=i*q;
      if(sj-xj/10000*10000>10000){
        printf("%ld",i);
        return 0;
      }
      i++;
    }
}
