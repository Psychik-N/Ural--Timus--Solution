#include <stdio.h>
#include <stdlib.h>
int cmp(int *a,int *b){
    return *a-*b;
}
int main(){
    int n,p,a[1001],i,level=0,x1=0,x2=0,cnt,pos;
    scanf("%d%d",&n,&p);
    for(i=0;i<n;i++)scanf("%d",a+i);
    qsort(a, n, 4, cmp);
    while(level<=p&&x1<n){
        cnt=0;
        pos=x1;
    more:
        cnt++;
        while(pos+1<n&&a[pos]==a[pos+1]){pos++;cnt++;}
        if(cnt*a[pos]<=p){level=a[pos];x1=++pos;if(x1<n)goto more;}
        x2++;
        level++;
    }
    printf("%d %d\n",x1,x2);
    return 0;
}
