#include <stdio.h>
int main(){
    int n,k,i=0,j;
    scanf("%d%d",&n,&k);
    for(j=0;j<=n-k;j++)printf("0 ");
    for(;j<n;j++){
        if(i<=0)i=-i+1;
        else i=-i;
        printf("%d ",i);
    }
    return 0;
}
