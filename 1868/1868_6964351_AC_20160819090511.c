#include <stdio.h>
#include <string.h>
char w[12][32];
int main(){
int bv=0,bn=0,n,k,i,tv,l;
char a[32],b[3],c[10];
for(i=0;i<12;i++)scanf("%s",w[i]);
scanf("%d",&n);
while(n-->0){
scanf("%d",&k);
tv=0;
while(k-->0){
scanf("%s%s%s",a,b,c);
if(strcmp(c,"gold")==0)l=0;
else if(strcmp(c,"silver")==0)l=4;
else l=8;
for(i=l;i<l+4;i++)if(strcmp(a,w[i])==0){
tv++;
break;
}
}
if(tv==bv)bn++;
else if(tv>bv){
bv=tv;
bn=1;
}
}
printf("%d\n",bn*5);
return 0;
}
