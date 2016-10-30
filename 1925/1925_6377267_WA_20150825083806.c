#include <stdio.h>
int main(){
int n,s1,s2=0,a,b,i;
scanf("%d%d",&n,&s1);
for(i=0;i<n;i++){
scanf("%d%d",&a,&b);
s1+=a;
s2+=b;
}
i=s1-s2-2*n;
if(i>=0)printf("%d\n",i);
else printf("Big Bang!\n");
return 0;
}