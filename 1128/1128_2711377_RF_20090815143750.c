﻿#include <stdio.h>
int main(){
    int c[7200][4],n,k,i,j,z[7200]={0},z2=0;
    scanf("%d",&n);
    if(n>7200)system("pause");
    for(i=1;i<=n;i++){
      scanf("%d",&c[i][0]);
      if(j>3)system("pause");
      for(j=1;j<=c[i][0];j++)
        scanf("%d",&c[i][j]);
    }
    for(i=1;i<=n;i++){
      k=0;
      for(j=1;j<=c[i][0];j++)
        if(z[c[i][j]]==0)
          k++;
      if(k>1){
        z[i]=1;
        z2++;
      }
    }
    for(i=1;i<=n;i++){
      k=0;
      for(j=1;j<=c[i][0];j++)
        if(z[c[i][j]]==z[i])
          k++;
      if(k>1){
              puts("NO SOLUTION");
              return 0;
      }
    }
    if(z2<n-z2){
      k=1;
      printf("%d\n",z2);
    }else if(z2>n-z2){
      k=0;
      printf("%d\n",n-z2);
    }else{
      k=z[1];
      printf("%d\n",z2);
    }
    for(i=1;i<=n;i++)
      if(z[i]==k)
        printf("%d ",i);
}
