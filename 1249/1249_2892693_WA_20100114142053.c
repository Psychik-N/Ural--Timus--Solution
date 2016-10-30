#include <stdio.h>
unsigned char in[2][10000];
void get(char *s){
     int p=0;
     while((s[p]=getchar())!='\n')p++;
     s[p]=0;
     getchar();
}
int main(){
    int i,j,m,n,on=0,t;
    scanf("%d%d\n",&n,&m);
    get(in[1]);
    for(i=1;i<n;i++){
      get(in[on]);
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
