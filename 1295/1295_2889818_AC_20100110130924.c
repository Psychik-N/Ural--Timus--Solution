#include <stdio.h>
int a[]={0,1,1,2,0,2,1,2,0,1,1,2,0,1,1,2,0,1,1,2,0};
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",a[n%20]);
}

