#include <stdio.h>
#include <string.h>
void sum(char *dest,char *src){
     char t[100]={0};
     int p=0,jw=0;
     while(dest[p]!=0||src[p]!=0||jw!=0){
       t[p]='0';
       if(dest[p]!=0)t[p]+=dest[p]-'0';
       if(src[p]!=0)t[p]+=src[p]-'0';
       if(jw!=0)t[p]++;
       jw=0;
       if(t[p]>'9'){
         jw=1;
         t[p]-=10;
       }
       p++;
     }
     strcpy(dest,t);
}
int sqr(char *dest,char *src){
     char t[200]={0};
     int ml;
     int at,i,j,l=strlen(src);
     dest[0]='0';
     for(i=0;i<l;i++){
       for(j=0;j<l;j++){
         at=i+j;
         t[at]+=(src[i]-'0')*(src[j]-'0');
         while(1){
           if(t[at]<10)break;
           t[at+1]+=t[at]/10;
           t[at]%=10;
           at++;
           if(ml<at+1)ml=at+1;
         }
       }
     }
     for(i=0;i<200;i++)dest[i]=t[i];
     return ml;
}
int main(){
    char f[2][501][100]={0},o[200]={0};
    int n,s,i,j,k,on=0;
    scanf("%d %d",&n,&s);
    if(s%2==1){
      printf("0");
      return 0;
    }
    if(s==0){
      printf("1");
      return 0;
    }
    s/=2;
    for(i=0;i<=9;i++)f[0][i][0]='1';
    for(i=10;i<=500;i++)f[0][i][0]='0';
    for(i=2;i<=n;i++){
      for(j=0;j<=s;j++){
        if(j>i*10)break;
        f[!on][j][0]='0';
        for(k=0;k<100;k++)f[!on][j][k]=0;
        for(k=0;k<10;k++){
          if(j-k<0)break;
          sum(f[!on][j],f[on][j-k]);
        }
      }
      on=!on;
    }
    sqr(o,f[on][s]);
    j=0;
    for(i=199;i>=0;i--){
      if(o[i]!=0)j=1;
      if(j==1)printf("%c",o[i]+'0');
    }
    if(j==0)printf("0");
}
