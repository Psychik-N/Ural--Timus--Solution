#include <stdio.h>
int to[110000],m1[110000]={0},m2[110000]={0},d[110000]={0};
int main(){
int a,n,i,now,step,a1=0,a2=0,fn=0;
scanf("%d",&n);
for(i=1;i<=n;i++){
scanf("%d",&a);
to[i]=a;
d[a]++;
}
for(i=1;i<=n;i++){
if(d[i])continue;
fn++;
now=i;
step=0;
while(1){
m1[now]=step;
step++;
m2[now]=fn;
now=to[now];
if(m2[now]==fn){
a1++;
a2+=m1[now]+1;
break;
}
if(m2[now]!=0){
a1++;
a2+=step;
break;
}
}
}
for(i=1;i<=n;i++){
if(m2[i])continue;
now=i;
while(1){
m2[now]=1;
now=to[now];
if(m2[now]==1)break;
}
a1++;
a2++;
}
printf("%d %d\n",a1,a2);
}





