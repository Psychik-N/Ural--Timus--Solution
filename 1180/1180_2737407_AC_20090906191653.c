#include <stdio.h>
int main(){
int s=0;
char tmp;
while((tmp=getchar())!=EOF)if(tmp>='0'&&tmp<='9')s+=tmp-'0';
if(s%3==0)puts("2");
else printf("1\n%d",s%3);
}
