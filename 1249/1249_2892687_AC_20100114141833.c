#include <stdio.h>
unsigned char in[2][10000];
int main(){
    int i,j,m,n,on=0,t;
    scanf("%d%d\n",&n,&m);
    gets(in[1]);
    for(i=1;i<n;i++){
      gets(in[on]);
      for(j=1;j<m;j++){
        t=j+j;
        if(in[0][t]+in[0][t-2]+in[1][t]+in[1][t-2]==195){
          puts("No");
          return 0;
        }
      }
      on=!on;
    }
    puts("Yes");
}
