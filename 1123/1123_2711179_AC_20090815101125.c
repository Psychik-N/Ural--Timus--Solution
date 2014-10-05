#include <string.h>
#include <stdio.h>
int main(){
    char in[2010];
    int l,i,r=0;
    gets(in);
    l=strlen(in);
      for(i=(l>>1)-1;i>=0;i--){
        if(in[i]>in[l-i-1])
          break;
        if(in[i]<in[l-i-1]){
          r=1;
          break;
        }
      }
      if(r==0){
        for(i=0;i<l>>1;i++)
          in[l-i-1]=in[i];
        puts(in);
        return 0;
      }
      if((l&1)==0)
        r=(l>>1)-1;
      else
        r=l>>1;
      in[r]++;
      while(in[r]>'9'){
        in[r]='0';
        r--;
        if(r<0)break;
        in[r]++;
      }
      if(r<0)putc('1',stdout);
      for(i=0;i<l>>1;i++)
        in[l-i-1]=in[i];
      if(r<0){
        in[l]='1';
        in[l+1]=0;
      }
      puts(in);
}
