#include <stdio.h>
#include <math.h>
int x[400],y[400],n,l,r,isx,sl=0,stk[400];
double s=0;
char m[400][400]={0};
int on(int i){
    return (x[i]-x[l])*(y[i]-y[r])==(x[i]-x[r])*(y[i]-y[l]);
}
void go(int p){
     int i,j;
     for(i=p+1;i<n;i++){
       if(on(i)==0||m[p][i])continue;
       m[p][i]=1;
       if(isx){
         if(x[i]<x[l])l=i;
         if(x[i]>x[r])r=i;
       }else{
         if(y[i]<y[l])l=i;
         if(y[i]>y[r])r=i;
       }
       stk[sl++]=i;
       go(i);
       return;
     }
     for(i=0;i<sl;i++)for(j=0;j<sl;j++)m[stk[i]][stk[j]]=1;
     s+=sqrt(pow(x[l]-x[r],2)+pow(y[l]-y[r],2));
}
int main(){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d%d",&x[i],&y[i]);
    for(i=0;i<n;i++)for(j=i+1;j<n;j++){
      if(m[i][j])continue;
      m[i][j]=1;
      sl=2;
      isx=1;
      if(x[i]==x[j]){
        isx=0;
        if(y[i]<y[j]){
          l=i;
          r=j;
        }else{
          l=j;
          r=i;
        }
      }else if(x[i]<x[j]){
        l=i;
        r=j;
      }else{
        l=j;
        r=i;
      }
      stk[0]=l;
      stk[1]=r;
      go(j);
    }
    printf("%.0lf\n",s);
}
