#include <stdio.h>
#include <ctype.h>
int main(){
    int n,i,o[10001]={0},nl=0,nr=0;
    char s[10001];
    scanf("%d%s",&n,s);
    for(i=0;i<n;i++){
        if(tolower(s[i])!=tolower(s[2*n-1-i])||islower(s[i])==islower(s[2*n-1-i])){
            puts("Impossible");
            return 0;
        }
        if(islower(s[i]))o[i]=n-nr++;
        else o[2*n-1-i]=++nl;
    }
    for(i=0;i<2*n;i++)if(o[i]!=0)printf("%d ",o[i]);
    return 0;
}
