#include <stdio.h>
int main(){
    int s=0,e=0;
    char c;
    while((c=getchar())!=EOF){
      if(s==0){
        if(c>='a'&&c<='z')e++;
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))s=1;
      }else if(s==1){
        if(c>='A'&&c<='Z')e++;
        if(!((c>='a'&&c<='z')||(c>='A'&&c<='Z'))){
          if(c=='.'||c=='!'||c=='?')s=0;
          else s=2;
        }
      }else{
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))s=1;
        if(c=='.'||c=='!'||c=='?')s=0;
      }
    }
    printf("%d",e);
}
