#include <stdio.h>
int ic=0,ie=0;
char n,nc='\n';
void out(){
printf("NO");
exit(0);
}
int main(){
int t;
void go(int);
while(nc=='\n'||nc=='\r'){if((t=getchar())==-1)break;nc=(char)t;}
while((t=getchar())!=EOF)go(t);
go('\n');
if(ie==0&&ic==0)printf("YES");
else printf("NO");
}
void go(int tt){
n=nc;
nc=(char)tt;
if(nc=='\r'||nc=='\n'){nc=n;return;}
else if(n=='*'&&nc==')'){if(ic==0)system("pause");ic=0;nc='\n';}
else if(ic!=0)return;
else if(n=='('&&nc=='*'){ic=1;nc='\n';}
else if(n=='(')ie++;
else if(n==')'){ie--;if(ie<0)out();}
else if(ie>0){if((n<'0'||n>'9')&&n!='='&&n!='+'&&n!='-'&&n!='*'&&n!='/')out();}
}
