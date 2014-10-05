#include <stdio.h>
int main(){
    int l[15010],n,i,m,in,p1,p2,c=0,z;
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&l[i]);
    scanf("%d",&m);
    for(i=0;i<m;i++){
      scanf("%d",&in);
      p1=0;
      p2=n-1;
      while(p1<p2){
        z=(p1+p2)/2;
        if(l[z]<in)p1=z+1;
        else if(l[z]>in)p2=z-1;
        else{p1=z;break;}
      }
      if(l[p1]==in)c++;
    }
    printf("%d\n",c);
}
