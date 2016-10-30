#include <stdio.h>
int a[]={0,1,1,2};
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",a[n%4]);
}
