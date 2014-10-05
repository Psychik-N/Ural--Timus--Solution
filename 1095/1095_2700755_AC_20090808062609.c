#include <stdio.h>
#include <string.h>
char lst[7][5]={"1324","1234","2341","1243","1342","2134","3241"};
int y(char *s){
    int ys=0,l=strlen(s),i;
    for(i=0;i<l;i++)
      ys=(ys*10+s[i]-'0')%7;
    return ys;
}
int main(){
    int n,i,j,l,l1,l2;
    char in[25],t1[25],t2[25],m[5],t3[25];
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%s",in);
      for(j=0;j<25;j++)
        t1[j]=t2[j]=0;
      for(j=1;j<5;j++)
        m[j]=0;
      l1=l2=0;
      l=strlen(in);
      for(j=0;j<l;j++){
        if(in[j]>='1'&&in[j]<='4'&&m[in[j]-'0']==0){
          m[in[j]-'0']=1;
        }else if(in[j]>'0'){
          t1[l1]=in[j];
          l1++;
        }else{
          t2[l2]='0';
          l2++;
        }
      }
      for(j=0;j<7;j++){
        strcpy(t3,t1);
        strcat(t3,lst[j]);
        strcat(t3,t2);
        if(y(t3)==0){
          printf("%s\n",t3);
          break;
        }
      }
    }
}
