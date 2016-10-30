#include <stdio.h>
int main(){
    int n,m,i,c=0,is,ie;
    double xl,s,e;
    scanf("%d%d",&n,&m);
    n--;
    m--;
    xl=(double)m/n;
    for(i=0;i<n;i++){
      s=i*xl;
      e=(i+1)*xl;
      is=(int)s;
      ie=(int)e;
      //if(e-ie<0.00001)ie--;
      //if(s-is>0.99999)is++;
      c+=ie-is+1;
    }
    printf("%d",c);
}
