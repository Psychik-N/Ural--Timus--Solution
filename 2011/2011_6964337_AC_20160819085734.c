#include <stdio.h>
int c(int n,int m){
  int i,r=1;
  if(m==0||n==m)return 1;
  if(n>=6)return 6;
  for(i=n-m+1;i<=n;i++)r*=i;
  for(i=1;i<=m;i++)r/=i;
  return r;
}
int main(){
  int count[3]={0},i,n,x;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&x);
    count[x-1]++;
  }
  if(c(n,count[0])*c(n-count[0],count[1])>=6)puts("Yes");
  else puts("No");
  return 0;
}
