#include <stdio.h>
int a[]={1,1,2,0};
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",a[n%4]);
}
