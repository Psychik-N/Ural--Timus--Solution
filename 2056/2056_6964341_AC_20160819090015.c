#include <stdio.h>
int main(){
int n,i,t,sum=0;
scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%d",&t);
if(t==3){puts("None");return 0;}
sum+=t;
}
if(sum==n*5)puts("Named");
else if(sum*2>=n*9)puts("High");
else puts("Common");
return 0;
}
