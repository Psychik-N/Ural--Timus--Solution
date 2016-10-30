#include <stdio.h>
int main(){
    char a[1010],b[1010];
    int ap=0,bp=0,ans=0;
    scanf("%s%s",a,b);
    while(a[ap]!=0||b[bp]!=0){
        if(a[ap]==0)bp++;
        else if(b[bp]==0)ap++;
        else{
            if(a[ap]!='L'&&b[bp]=='L')ap++;
            else if(a[ap]=='L'&&b[bp]!='L')bp++;
            else{
                ap++;
                bp++;
            }
        }
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}
