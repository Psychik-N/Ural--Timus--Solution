#include <stdio.h>
#include <ctype.h>
int l[10001],r[10001],a[10001],x[10001],m[10001]={0},ymq[10001][2],ql=0;
char s[10001];
int match(char a,char b){
    if(tolower(a)!=tolower(b)||islower(a)==islower(b))return 0;
    return 1;
}
int main(){
    int n,i,y=0,c,d;
    scanf("%d%s",&n,s);
    for(i=0;i<2*n;i++)if(islower(s[i]))x[i]=++y;
    for(i=0;i<2*n;i++)l[i]=i-1;
    for(i=0;i<2*n;i++)r[i]=i+1;
    l[0]=2*n-1;
    r[2*n-1]=0;
    for(i=0;i<2*n;i++)if(m[i]==0&&m[l[i]]==0&&match(s[i],s[l[i]])){
        m[i]=m[l[i]]=1;
        ymq[ql][0]=i;
        ymq[ql][1]=1;
        ql++;
    }
    while(ql-->0){
        c=ymq[ql][0];
        d=ymq[ql][1];
        if(d==1){
            c=l[c];
            d=r[c];
        }else{
            d=r[c];
        }
        if(islower(s[c]))a[d]=x[c];
        else a[c]=x[d];
        r[l[c]]=r[d];
        l[r[d]]=l[c];
        if(m[l[c]]==0&&m[r[d]]==0&&match(s[l[c]],s[r[d]])){
            m[l[c]]=m[r[d]]=1;
            ymq[ql][0]=l[c];
            ymq[ql][1]=2;
            ql++;
        }
    }
    for(i=0;i<2*n;i++)if(m[i]==0){puts("Impossible");return 0;}
    for(i=0;i<2*n;i++)if(isupper(s[i]))printf("%d ",a[i]);
    return 0;
}
