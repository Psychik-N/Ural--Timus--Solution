#include <stdio.h>
#include <string.h>
int pl=0,p[6],c[6]={0};
char n[6][25];
int main(){
  int i,j,x,bp=0x7fffffff,bc=0,bi;
  char s[25];
  for(i=0;i<6;i++){
    scanf("%s",s);
    scanf("%s%d",s,&x);
    for(j=0;j<pl;j++)if(strcmp(s,n[j])==0){
      c[j]++;
      if(x<p[j])p[j]=x;
      goto nxt;
    }
    strcpy(n[pl],s);
    c[pl]=1;
    p[pl++]=x;
    nxt:;
  }
  for(i=0;i<pl;i++)
    if(c[i]>bc||c[i]==bc&&p[i]<bp){
      bp=p[i];
      bc=c[i];
      bi=i;
    }
  printf("%s\n",n[bi]);
  return 0;
}
