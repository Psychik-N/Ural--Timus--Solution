#include <stdio.h>
#include <limits.h>
long long vec[100000];
int vl=3;
void swap(long long *a,long long *b){
    *a^=*b^=*a^=*b;
}
int main(){
    int i,j,ans=0;
    long long bv;
    scanf("%lld%lld%lld",vec,vec+1,vec+2);
    if(vec[0]>=vec[1])swap(vec,vec+1);
    if(vec[1]>=vec[2])swap(vec+1,vec+2);
    if(vec[0]>=vec[1])swap(vec,vec+1);
    while(1){
        bv=LLONG_MAX;
        for(i=1;i<vl;i++)if(vec[i]-vec[i-1]<bv)bv=vec[i]-vec[i-1];
        ans++;
        if(bv==0){
            printf("%d\n",ans);
            break;
        }
        for(i=0;i<vl;i++)if(bv<=vec[i]){
            for(j=vl-1;j>=i;j--)vec[j+1]=vec[j];
            vec[i]=bv;
            vl++;
            break;
        }
    }
    return 0;
}
