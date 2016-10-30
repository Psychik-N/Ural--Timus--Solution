#include <stdio.h>
#include <stdlib.h>
struct S{
int l,r;
}s[11000];
int top=-1,y[11000]={0};
int cmp(const void *a,const void *b){
return *(int*)a-*(int*)b;
}
int main(){
int m,n=0,i=0,a,b,c=-1;
scanf("%d",&m);
while(1){
scanf("%d%d",&a,&b);
if(a==0&&b==0)break;
s[n].l=a;
s[n].r=b;
n++;
}
qsort(s,n,sizeof(struct S),cmp);
while(1){
if(i<n&&s[i].l<=0){
if(top==-1||s[top].r<s[i].r)top=i;
i++;
}else break;
}
while(1){
if(top!=-1&&s[top].r>c){
y[top]=1;
c=s[top].r;
if(c>=m)break;
while(1){
if(i<n&&s[i].l<=c){
if(top==-1||s[top].r<s[i].r)top=i;
i++;
}else break;
}
}else{
printf("No solution\n");
return 0;
}
}
m=0;
for(i=0;i<n;i++)m+=y[i];
printf("%d\n",m);
for(i=0;i<n;i++)if(y[i])printf("%d %d\n",s[i].l,s[i].r);
return 0;
}
