#include <stdio.h>
int part[11],n,total=0;
int c(int a,int b){
    int i,res=1;
    if(b>a/2)b=a-b;
    for(i=a;i>a-b;i--)res*=i;
    for(i=b;i>0;i--)res/=i;
    return res;
}
void ok(int len){
     int i,res=1,left=n;
     for(i=0;i<len;i++){
       res*=c(left,part[i]);
       left-=part[i];
     }
     total+=res;
}
void go(int level,int left){
     int i;
     if(left==0)ok(level);
     else{
       for(i=1;i<=left;i++){
         part[level]=i;
         go(level+1,left-i);
       }
     }
}
int main(){
    while(1){
      scanf("%d",&n);
      if(n==-1)break;
      total=0;
      go(0,n);
      printf("%d\n",total);
    }
}
