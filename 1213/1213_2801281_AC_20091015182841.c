#include <stdio.h>
#include <string.h>
int main(){
    char i1[30],i2[30],nm[70][30];
    int n,i,j,l=1,sl,l1;
    scanf("%s",nm[0]);
    while(1){
      scanf("%s",i1);
      if(i1[0]=='#')break;
      sl=strlen(i1);
      for(i=0;i<sl;i++)if(i1[i]=='-'){
        l1=i;
        i1[i]=0;
        break;
      }
      for(i=l1+1;i<sl;i++)i2[i-l1-1]=i1[i];
      i2[sl-l1-1]=0;
      for(j=0;j<l;j++)if(strcmp(i1,nm[j])==0)goto n1;
      strcpy(nm[l],i1);
      l++;
      n1:
      for(j=0;j<l;j++)if(strcmp(i2,nm[j])==0)goto n2;
      strcpy(nm[l],i2);
      l++;
      n2:;
    }
    printf("%d\n",l-1);
}
