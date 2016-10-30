#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long i64;
int cmp(int *a,int *b){
    return *b-*a;
}
i64 C(int n,int r){
    i64 ans[27][27]={0};
    int i,j;
    for(i=0;i<27;i++){
        ans[i][0]=1;
        for(j=1;j<=i;j++)ans[i][j]=ans[i-1][j]+ans[i-1][j-1];
    }
    return ans[n][r];
}
int main(){
    int count[26]={0},i,n=0,k,ans1=0,c1=0,c2=0;
    char c;
    while(1){
        c=getchar();
        if(c>'z'||c<'a')break;
        n++;
        count[c-'a']++;
    }
    qsort(count, 26, 4, cmp);
    scanf("%d",&k);
    for(i=0;i<k;i++)ans1+=count[i];
    if(count[k-1]!=0)for(i=0;i<26;i++)if(count[i]==count[k-1]){
        c2++;
        if(i<k)c1++;
    }
    printf("%d %lld\n",ans1,C(c2,c1));
    return 0;
}
