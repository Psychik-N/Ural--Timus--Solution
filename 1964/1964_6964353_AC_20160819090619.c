#include <stdio.h>
int main(){
    int n,k,a,b,ans;
    scanf("%d%d%d%d",&n,&k,&a,&b);
    ans=a+b-n<0?0:a+b-n;
    while(k-->2){
        scanf("%d",&a);
        ans=ans+a-n<0?0:ans+a-n;
    }
    printf("%d\n",ans);
    return 0;
}
