#include <stdio.h>
unsigned char in[2][10000];
int main(){
    int i,j,m,n,on=0,t,tt;
    scanf("%d%d\n",&n,&m);
    gets(in[1]);
    for(i=1;i<n;i++){
      gets(in[on]);
      for(j=1;j<m;j++){
        t=j+j;
        tt=t-2;
        if(in[0][t]+in[0][tt]+in[1][t]+in[1][tt]==195){
          puts("No");
          return 0;
        }
      }
      on=!on;
    }
    puts("Yes");
}
