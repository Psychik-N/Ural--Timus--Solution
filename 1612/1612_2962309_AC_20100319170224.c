#include <stdio.h>
#include <string.h>
int main(){
    int a=0,b=0,i,l,sl=0;
    char stk[20000],in[20000];
    while(gets(in)){
      l=strlen(in);
      in[l]='.';
      l++;
      for(i=0;i<l;i++){
        if(in[i]>='a'&&in[i]<='z')stk[sl++]=in[i];
        else{
          stk[sl]=0;
          if(strcmp(stk,"tram")==0)a++;
          else if(strcmp(stk,"trolleybus")==0)b++;
          sl=0;
        }
      }
    }
    if(a>b)printf("Tram driver\n");
    else if(a<b)printf("Trolleybus driver\n");
    else printf("Bus driver\n");
}
