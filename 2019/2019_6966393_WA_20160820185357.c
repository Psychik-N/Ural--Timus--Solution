#include <stdio.h>
#include <ctype.h>
int l[10001],r[10001],a[10001],x[10001];
char s[10001];
int match(char a,char b){
    if(tolower(a)!=tolower(b)||islower(a)==islower(b))return 0;
    return 1;
}
int main(){
    int n,i,y=0;
    scanf("%d%s",&n,s);
    for(i=0;i<2*n;i++)if(islower(s[i]))x[i]=++y;
    for(i=0;i<2*n;i++)l[i]=i-1;
    for(i=0;i<2*n;i++)r[i]=i+1;
    l[0]=2*n-1;
    r[2*n-1]=0;
    for(i=0;i<2*n;i++){
        if(match(s[i],s[l[i]])){
            a[i]=x[l[i]];
            l[r[i]]=l[l[i]];
            r[l[l[i]]]=r[i];
        }else if(match(s[i],s[r[i]])){
            a[i]=x[r[i]];
            r[l[i]]=r[r[i]];
            l[r[r[i]]]=l[i];
        }else{
            puts("Impossible");
            return 0;
        }
    }
    for(i=0;i<2*n;i++)if(isupper(s[i]))printf("%d ",a[i]);
    return 0;
}
