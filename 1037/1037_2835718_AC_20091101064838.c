#include <stdio.h>
int main(){
  int i,j,k,num,time,t,a[30001];
  char ch;
  for(i=1;i<=30000;i++)a[i]=-600;
  while(scanf("%d %c",&time,&ch)!=EOF){
    if(ch=='+'){
      t=time-600;
      i=1;
      while(a[i]>t)i++;
      printf("%d\n",i);
      a[i]=time;
    }else{
      scanf("%d",&num);
      if(time-a[num]>=600)printf("-\n");
      else{
        printf("+\n");
        a[num]=time;
      }
    }
  }
}
