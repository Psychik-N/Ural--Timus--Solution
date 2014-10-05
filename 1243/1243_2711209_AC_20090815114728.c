#include <string.h>
int main(){
    char in[60],out[2];
    int ys=0,l,i;
    gets(in);
    l=strlen(in);
    for(i=0;i<l;i++)
      ys=(ys*10+(in[i]-48))%7;
    out[0]=ys+48;
    out[1]=0;
    puts(out);
}
