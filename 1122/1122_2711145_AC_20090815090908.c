#include <stdio.h>
int main(){
    char m[65536]={0},f[3][3],in[5];
    int i,j,a,b,q[2][65536],ql[2]={1},on=0,t=0,c=0;
    for(i=3;i>=0;i--){
      gets(in);
      for(j=3;j>=0;j--)
        if(in[3-j]=='W')
          t+=1<<(i*4+j);
    }
    for(i=0;i<3;i++)
      gets(f[i]);
    if(t==0||t==65535){
      puts("0");
      return 0;
    }
    q[0][0]=t;
    m[t]=1;
    while(ql[on]>0){
      c++;
      ql[!on]=0;
      for(i=0;i<ql[on];i++){
        for(j=0;j<16;j++){
          t=q[on][i];
          for(a=0;a<3;a++){
            if(j>11&&a==0)continue;
            if(j<4&&a==2)continue;
            for(b=0;b<3;b++){
              if(j%4==3&&b==0)continue;
              if(j%4==0&&b==2)continue;
              if(f[a][b]=='1')
                t=t^(1<<(j+(1-a)*4+(1-b)));
            }
          }
          if(t==0||t==65535){
            printf("%d",c);
            return 0;
          }
          if(m[t]==1)continue;
          m[t]=1;
          q[!on][ql[!on]]=t;
          ql[!on]++;
        }
      }
      on=!on;
    }
    puts("Impossible");
}
