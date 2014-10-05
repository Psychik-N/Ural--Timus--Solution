#include <stdio.h>
#include <math.h>
int main(){
    int i,j,k,m,n;
    double b,c,s,t;
    scanf("%d %lf",&n,&c);
    n--;
    m=(int)(sqrt(c));
    if(m>=n){
      printf("0.00");
      return 0;
    }
    if(c/m<=m+1){
      b=m+c/m;
      s=n*n-b*n+c;
    }else s=1e100;
    m++;
    if(c/m>=m-1){
      b=m+c/m;
      t=n*n-b*n+c;
    }else t=1e100;
    if(s<t)printf("%.2lf",s);
    else printf("%.2lf",t);
}
