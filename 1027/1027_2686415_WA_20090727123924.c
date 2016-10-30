#include <stdio.h>
#include <string.h>
int i,r=1,ic=0,ie=0,t,f;
unsigned char n,nc,cl[20]="=+-*/0123456789";
int main(){
void go(int t);
nc=(unsigned char)getchar();
while((t=getchar())!=EOF)go(t);
go(10);
if(r)printf("YES");
else printf("NO");
}
void go(int t){
n=nc;
nc=(unsigned char)t;
if(n==10||n==13);
else if(n=='*'&&nc==')'){ic=0;nc=10;}
else if(ic);
else if(n=='('&&nc=='*'){ic=1;nc=10;}
else if(n=='(')ie++;
else if(n==')'){ie--;if(ie<0)r=0;}
else if(ie){f=0;for(i=0;i<15;i++)if(n==cl[i])f=1;if(f==0)r=0;}
}
