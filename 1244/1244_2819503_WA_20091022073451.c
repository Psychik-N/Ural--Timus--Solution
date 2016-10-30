#include <stdio.h>
char f[101][100010]={0};
int f2[101][100010],h[1010];
char go(int a,int b,int c){
     int s=0;
     if(a==0&&b!=0)return -1;
     if(f[a][b]!=0)return f[a][b];
     if(b-h[a]>=0&&go(a-1,b-h[a],0)==1){
       s=1;
       f2[a][b]=b-h[a];
     }
     if(go(a-1,b,0)==1){
       s+=2;
       f2[a][b]=b;
     }
     if(c==1&&s==3)return -2;
     if(s!=0)return f[a][b]=1;
     else return f[a][b]=-1;
}
int main(){
    int n,i,y,s=0,in,o[1010],ol=0;
    scanf("%d%d",&y,&n);
    for(i=1;i<=n;i++){
      scanf("%d",&h[i]);
      s+=h[i];
    }
    y=s-y;
    f[0][0]=1;
    in=go(n,y,1);
    if(in==-2)printf("-1");
    else if(in==-1)printf("0");
    else{
      for(i=n;i>=1;i--)if(f2[i][y]!=y){
        y-=h[i];
        o[ol++]=i;
      }
      for(i=ol-1;i>=0;i--)printf("%d ",o[i]);
    }
}
