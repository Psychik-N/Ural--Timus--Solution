#include <stdio.h>
int i,r=1,ic=0,ie=0,t,f;
char n,nc,cl[20]="=+-*/0123456789";
int main(){
void go(int tt);
nc=(char)getch();
while((t=getch())!=EOF)go(t);
go(10);
if(r!=0&&ie==0&&ic==0)printf("YES");
else printf("NO");
}
void go(int tt){
n=nc;
nc=(char)tt;
if(n==10||n==13)return;
else if(n=='*'&&nc==')'){if(ic==0)r=0;ic=0;nc=10;}
else if(ic)return;
else if(n=='('&&nc=='*'){ic=1;nc=10;}
else if(n=='(')ie++;
else if(n==')'){ie--;if(ie<0)r=0;}
else if(ie){f=0;for(i=0;i<15;i++)if(n==cl[i])f=1;if(f==0)r=0;}
}
