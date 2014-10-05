#include <stdio.h>
int ans=0,p[51],n;
int abs(int a){
    if(a>=0)return a;
    return -a;
}
void go(int a,int b,int c){
     int i;
     for(i=1;i<=n;i++){
       if(i!=a&&abs(i-a)==abs(p[i]-p[a]))return;
       if(i!=b&&abs(i-b)==abs(p[i]-p[b]))return;
       if(i!=c&&abs(i-c)==abs(p[i]-p[c]))return;
     }
     ans++;
}
int main(){
    int i,j,k,t;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
      scanf("%d",&j);
      scanf("%d",&p[j]);
    }
    for(i=1;i<=n-2;i++){
      for(j=i+1;j<=n-1;j++){
        for(k=j+1;k<=n;k++){
          t=p[i];p[i]=p[j];p[j]=p[k];p[k]=t;
          go(i,j,k);
          t=p[i];p[i]=p[j];p[j]=p[k];p[k]=t;
          go(i,j,k);
          t=p[i];p[i]=p[j];p[j]=p[k];p[k]=t;
        }
      }
    }
    printf("%d",ans);
}
