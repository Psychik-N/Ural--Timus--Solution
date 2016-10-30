#include <stdio.h>
#include <stdlib.h>
int v[101];
int cmp(int *a,int *b){
  return *a-*b;
}
int main(){
  int n,i,a=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",v+i);
  qsort(v,n,sizeof(int),cmp);
  for(i=0;i<n;i++)a+=v[i];
  a+=v[n-1];
  printf("%d\n",a);
  return 0;
}
