#include <stdio.h>
int ic=0,ie=0;
unsigned char n,nc;
void out(){
printf("NO");
exit(0);
}
int main(){
int t;
void go(int);
nc=(unsigned char)getchar();
while((t=getchar())!=EOF)go(t);
go('\n');
if(ie==0&&ic==0)printf("YES");
else printf("NO");
}
void go(int tt){
n=nc;
nc=(unsigned char)tt;
if(n=='\r'||n=='\n')return;
else if(n=='*'&&nc==')'){if(ic==0)out();ic=0;nc='\n';}
else if(ic!=0)return;
else if(n=='('&&nc=='*'){ic=1;nc='\n';}
else if(n=='(')ie++;
else if(n==')'){ie--;if(ie<0)out();}
else if(ie>0){if((n<'0'||n>'9')&&n!='='&&n!='+'&&n!='-'&&n!='*'&&n!='/')out();}
}
