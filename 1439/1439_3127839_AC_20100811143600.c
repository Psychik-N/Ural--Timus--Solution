#include <stdio.h>
int db[11000]={0,2000000000},dl=2;
int select(int n){
    int l=0,r=dl-1,m,lv,rv;
    while(l!=r){
      m=(l+r)/2;
      lv=db[m]-m+1;
      rv=db[m+1]-m-1;
      if(n>=lv&&n<=rv)break;
      if(n<lv)r=m;
      else if(n>rv)l=m+1;
    }
    m=(l+r)/2;
    return n+m;
}
int main(){
    int t,n,i,j,m,h;
    char c[5];
    scanf("%d%d",&n,&m);
    for(h=0;h<m;h++){
      scanf("%s %d",c,&t);
      if(c[0]=='D'){
        t=select(t);
        if(db[dl-1]<t)db[dl++]=t;
        else{
          for(i=0;i<dl-1;i++)if(db[i]<t&&db[i+1]>t)break;
          for(j=dl-1;j>i;j--)db[j+1]=db[j];
          db[i+1]=t;
          dl++;
        }
      }else printf("%d\n",select(t));
    }
}
