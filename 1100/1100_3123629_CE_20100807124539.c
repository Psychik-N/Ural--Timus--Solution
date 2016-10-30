#include <stdio.h>
int bh[101][150010],l[101]={0};
int main(){
    int n,i,k,j,a,b,s,il,pl;
    char c,buf[10],ic[2];
    do{
         c=getchar();
    }while(c<48||c>57);
    s=c-48;
    while(1){
      c=getchar();
      if(c<48||c>57)break;
      s=s*10+c-48;
    }
    n=s;
    for(i=0;i<n;i++){
                         do{
         c=getchar();
    }while(c<48||c>57);
    s=c-48;
    while(1){
      c=getchar();
      if(c<48||c>57)break;
      s=s*10+c-48;
    }
      a=s;
          do{
         c=getchar();
    }while(c<48||c>57);
    s=c-48;
    while(1){
      c=getchar();
      if(c<48||c>57)break;
      s=s*10+c-48;
    }
      b=s;
      bh[b][l[b]]=a;
      l[b]++;
    }
    for(i=100;i>=0;i--){
      if(i<100&&i>9){
        il=2;
        ic[0]=i/10+48;
        ic[1]=i%10+48;
      }else if(i<10){
        il=1;
        ic[0]=i+48;
      }
      for(j=0;j<l[i];j++){
                          s=bh[i][j];
     if(s==0)
       putchar(48);
     else{
          pl=0;
     while(s){
       buf[pl]=s%10+48;
       pl++;
       s/=10;
     }
     for(k=pl-1;k>=0;k--)putchar(buf[k]);
     }
        putchar(' ');
        if(i==100){putchar(49);putchar(48);putchar(48);}
        else if(il==2){putchar(ic[0]);putchar(ic[1]);}
        else putchar(ic[0]);
        putchar('\n');
      }
    }
}
