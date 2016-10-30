#include <stdio.h>
int main(){
    int c=0,n,i;
    char in,s[2][30001],f=0,on=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%c",&in);
      while(in!='<'&&in!='>')scanf("%c",&in);
      if(in=='<')
        s[0][i]=0;
      else if(in=='>')
        s[0][i]=1;
    }
    while(f==0){
      f=1;
      s[on][n]=25;
      for(i=1;i<=n;i++){
        if(s[on][i-1]==1&&s[on][i]==0){
          s[!on][i-1]=0;
          s[!on][i]=1;
          c++;
          i++;
          f=0;
        }else{
          s[!on][i-1]=s[on][i-1];
        }
      }
      on=!on;
    }
    printf("%d",c);
}
