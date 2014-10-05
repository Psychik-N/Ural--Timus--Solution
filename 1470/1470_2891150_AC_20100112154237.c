#include <stdio.h>
int c[130][130][130]={0},n;
int low(int a){
       return a&(a^(a-1));
}
void add(int x,int y,int z,int num){
     int i,j,k;
     for(i=x;i<=n;i+=low(i))
     for(j=y;j<=n;j+=low(j))
     for(k=z;k<=n;k+=low(k))
     c[i][j][k]+=num;
}
int sum(int x,int y,int z){
    int i,j,k,s=0;
    for(i=x;i>0;i-=low(i))
    for(j=y;j>0;j-=low(j))
    for(k=z;k>0;k-=low(k))
    s+=c[i][j][k];
    return s;
}
int main(){
    int m,x1,x2,y1,y2,z1,z2,k;
    scanf("%d",&n);
    while(1){
      scanf("%d",&m);
      if(m==3)return 0;
      if(m==1){
        scanf("%d%d%d%d",&x1,&y1,&z1,&k);
        add(x1+1,y1+1,z1+1,k);
      }else{
        scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
        printf("%d\n",sum(x2+1,y2+1,z2+1)-sum(x1,y2+1,z2+1)-sum(x2+1,y1,z2+1)-sum(x2+1,y2+1,z1)
               +sum(x2+1,y1,z1)+sum(x1,y2+1,z1)+sum(x1,y1,z2+1)-sum(x1,y1,z1));
      }
    }
}
