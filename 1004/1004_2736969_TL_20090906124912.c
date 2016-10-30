#include <stdio.h>
int ms(){
    int s;
    char c;
    do{
      c=getchar();
      if(c=='-')return -1;
    }while(c<'0'||c>'9');
    s=c-'0';
    while(1){
      c=getchar();
      if(c<'0'||c>'9')break;
      s=s*10+c-'0';
    }
    return s;
}
int main(){
    int n,m,i,j,from[110],w[110][110],dist[110],a,b,c,t,mark[110],bv=1000000000,bi[10010],bl,mv,mi,ti[10010],tl;
    while(1){
      n=ms();
      if(n==-1)break;
      m=ms();
      for(i=0;i<110;i++)from[i]=0;
      for(i=0;i<110;i++)for(j=0;j<110;j++)w[i][j]=1000000000;
      bv=1000000000;
      for(i=1;i<=m;i++){
        a=ms();
        b=ms();
        c=ms();
        if(c<w[a][b])w[a][b]=w[b][a]=c;
      }
      if(n<3){
        puts("No solution.");
        continue;
      }
      for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
          if(w[i][j]==1000000000)continue;
          t=w[i][j];
          w[i][j]=w[j][i]=1000000000;
          for(a=1;a<=n;a++){
            if(a!=i)mark[a]=0;
            else mark[a]=1;
            dist[a]=w[i][a];
            from[a]=i;
          }
          from[i]=0;
          for(a=0;a<n-2;a++){
            mv=1000000000;
            mi=i;
            for(b=1;b<=n;b++){
              if(mark[b]==0&&dist[b]<mv){
                mv=dist[b];
                mi=b;
              }
            }
            if(mi!=i)mark[mi]=1;
            else break;
            for(b=1;b<=n;b++)if(mark[b]==0&&dist[mi]+w[mi][b]<dist[b]){
              dist[b]=dist[mi]+w[mi][b];
              from[b]=mi;
            }
          }
          if(dist[j]<1000000000){
            b=j;
            tl=0;
            while(b!=0){
              ti[tl]=b;
              tl++;
              b=from[b];
            }
            if(dist[j]+t<bv){
              for(c=0;c<tl;c++)bi[c]=ti[c];
              bl=tl;
              bv=dist[j]+t;
            }
          }
          w[i][j]=w[j][i]=t;
        }
      }
      if(bv<1000000000){
        for(i=0;i<bl;i++)printf("%d ",bi[i]);
        printf("\n");
      }else puts("No solution.");
    }
}
