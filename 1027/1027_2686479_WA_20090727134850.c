﻿#include <stdio.h>
int i,r=1,ic=0,ie=0,t,f;
char n,nc,cl[20]="=+-*/0123456789";
int main(){
void go(int tt);
nc=(char)getchar();
while((t=getchar())!=EOF)go(t);
go('\n');
if(r!=0&&ie==0&&ic==0)printf("YES");
else printf("NO");
}
void go(int tt){
n=nc;
nc=(char)tt;
if(n=='\r'||n=='\n')return;
else if(n=='*'&&nc==')'){if(ic==0)r=0;ic=0;nc='\n';}
else if(ic!=0)return;
else if(n=='('&&nc=='*'){ic=1;nc='\n';}
else if(n=='(')ie++;
else if(n==')'){ie--;if(ie<0)r=0;}
else if(ie!=0){f=0;for(i=0;i<16;i++)if(n==cl[i])f=1;if(f==0)r=0;}
}
