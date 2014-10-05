#include <stdio.h>
#include <string.h>
int main(){
    int n,i,x[20],take[20]={0};
    char i1[25],i2[25],i3[25],f[20][3][25];
    scanf("%d\n",&n);
    for(i=0;i<n;i++){
      scanf("%s %s %s\n",i1,i2,i3);
      if(strcmp(i1,i2)<=0&&strcmp(i1,i3)<=0){
        strcpy(f[i][0],i1);
        if(strcmp(i2,i3)<=0){
          strcpy(f[i][1],i2);
          strcpy(f[i][2],i3);
        }else{
          strcpy(f[i][1],i3);
          strcpy(f[i][2],i2);
        }
      }else if(strcmp(i2,i1)<=0&&strcmp(i2,i3)<=0){
        strcpy(f[i][0],i2);
        if(strcmp(i1,i3)<=0){
          strcpy(f[i][1],i1);
          strcpy(f[i][2],i3);
        }else{
          strcpy(f[i][1],i3);
          strcpy(f[i][2],i1);
        }
      }else{
        strcpy(f[i][0],i3);
        if(strcmp(i1,i2)<=0){
          strcpy(f[i][1],i1);
          strcpy(f[i][2],i2);
        }else{
          strcpy(f[i][1],i2);
          strcpy(f[i][2],i1);
        }
      }
    }
    for(i=0;i<n;i++){
      scanf("%d",&x[i]);
      x[i]--;
    }
    for(i=1;i<n;i++){
      if(strcmp(f[x[i-1]][take[x[i-1]]],f[x[i]][0])<0)take[x[i]]=0;
      else if(strcmp(f[x[i-1]][take[x[i-1]]],f[x[i]][1])<0)take[x[i]]=1;
      else if(strcmp(f[x[i-1]][take[x[i-1]]],f[x[i]][2])<0)take[x[i]]=2;
      else{
        puts("IMPOSSIBLE");
        return 0;
      }
    }
    for(i=0;i<n;i++)puts(f[x[i]][take[x[i]]]);
}
