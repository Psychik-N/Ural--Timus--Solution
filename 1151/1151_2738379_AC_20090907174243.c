#include <stdio.h>
#include <string.h>
#pragma comment(linker,"/STACK:16777216")
int p,l;
char in[10000];
int min(int a,int b){
    if(a<b)return a;
    return b;
}
int max(int a,int b){
    if(a>b)return a;
    return b;
}
int ms(){
    int s;
    char c;
    do{
      c=in[p];
      p++;
      if(p>l)return -1;
    }while(c<'0'||c>'9');
    s=c-'0';
    while(1){
      c=in[p];
      p++;
      if(c<'0'||c>'9')break;
      s=s*10+c-'0';
    }
    return s;
}
int main(){
    int i,j,k,m,n=0,dy[12],js[12][205][205]={0},yg[12]={0},s,x,y,a,b,num,dis,mv,mi;
    scanf("%d\n",&m);
    for(i=0;i<m;i++){
      gets(in);
      l=strlen(in);
      p=0;
      x=ms();
      y=ms();
      while(1){
        num=ms();
        if(num==-1)break;
        dis=ms();
        k=-1;
        for(j=0;j<n;j++)if(dy[j]==num){
          k=j;
          break;
        }
        if(k==-1){
          dy[n]=num;
          k=n;
          n++;
        }
        yg[k]++;
        if(dis==0)js[k][x][y]++;
        else{
          for(a=max(x-dis+1,1);a<min(x+dis,201);a++){
            if(y-dis>0)js[k][a][y-dis]++;
            if(y+dis<=200)js[k][a][y+dis]++;
          }
          for(a=max(y-dis+1,1);a<min(y+dis,201);a++){
            if(x-dis>0)js[k][x-dis][a]++;
            if(x+dis<=200)js[k][x+dis][a]++;
          }
          if(x-dis>0&&y-dis>0)js[k][x-dis][y-dis]++;
          if(x-dis>0&&y+dis<=200)js[k][x-dis][y+dis]++;
          if(x+dis<=200&&y-dis>0)js[k][x+dis][y-dis]++;
          if(x+dis<=200&&y+dis<=200)js[k][x+dis][y+dis]++;
        }
      }
    }
    for(i=0;i<n;i++){
      mv=50000;
      for(j=0;j<n;j++){
        if(dy[j]<mv){
          mv=dy[j];
          mi=j;
        }
      }
      x=y=-1;
      for(a=1;a<=200;a++){
        for(b=1;b<=200;b++){
          if(js[mi][a][b]==yg[mi]){
            if(x==-1){
              x=a;
              y=b;
            }else{
              y=-1;
              break;
            }
          }
        }
      }
      if(x!=-1&&y!=-1)printf("%d:%d,%d\n",mv,x,y);
      else printf("%d:UNKNOWN\n",mv);
      dy[mi]=50000;
    }
}
