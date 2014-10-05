#include <stdio.h>
#include <string.h>
#pragma comment(linker,"/STACK:16777216")
char in[10000000];
int main(){
    char stk[10],sl;
    int l,i,n,j;
    scanf("%d\n",&n);
    for(i=n;i>0;i--){
      gets(in);
      l=strlen(in);
      sl=0;
      for(j=l-1;j>=0;j--){
        if(sl==1&&in[j]=='i'&&stk[0]=='n')sl=0;
        else if(sl==2&&in[j]=='o'&&stk[1]=='n'&&stk[0]=='e')sl=0;
        else if(sl==2&&in[j]=='o'&&stk[1]=='u'&&stk[0]=='t')sl=0;
        else if(sl==4&&in[j]=='p'&&stk[3]=='u'&&stk[2]=='t'&&stk[1]=='o'&&stk[0]=='n')sl=0;
        else if(sl==4&&in[j]=='i'&&stk[3]=='n'&&stk[2]=='p'&&stk[1]=='u'&&stk[0]=='t')sl=0;
        else if(sl==5&&in[j]=='o'&&stk[4]=='u'&&stk[3]=='t'&&stk[2]=='p'&&stk[1]=='u'&&stk[0]=='t')sl=0;
        else{
          stk[sl]=in[j];
          sl++;
          if(sl>6)goto wrong;
        }
      }
      if(sl!=0)goto wrong;
      puts("YES");
      continue;
      wrong:
      puts("NO");
    }
}
