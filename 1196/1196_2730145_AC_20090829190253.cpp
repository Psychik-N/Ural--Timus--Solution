#include <stdio.h>
#pragma comment(linker,"/STACK:16777216")
struct H{
       int num;
       struct H *next;
}*h[65536]={0},*w;
int main(){
    int n,i,in,t,c=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d",&in);
      t=in-((in>>16)<<16);
      w=new H();
      w->num=in;
      w->next=h[t];
      h[t]=w;
    }
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d",&in);
      t=in-((in>>16)<<16);
      w=h[t];
      while(w!=0){
        if(w->num==in){
          c++;
          break;
        }
        w=w->next;
      }
    }
    printf("%d\n",c);
}
