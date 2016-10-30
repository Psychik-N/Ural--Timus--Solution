#include <stdio.h>
int main(){
char in[1000010],c;
int ys,s=0,i,j,l=0,bv=2;
while((c=getchar())!=EOF){
if(c>='0'&&c<='9'){in[l]=c-'0';l++;}
if(c>='A'&&c<='z'){in[l]=c+10-'A';l++;}
}
if(in[0]==0){puts("2");return 0;}
for(i=0;i<l;i++){if(in[i]>bv)bv=in[i];if(in[i]==36)goto out;}
for(i=bv+1;i<36;i++){
ys=0;
for(j=0;j<l;j++)ys=(ys*i+(int)in[j])%(i-1);
if(ys==0){
s=1;
break;
}
}
out:
if(s)printf("%d\n",i);
else puts("No solution.");
}
