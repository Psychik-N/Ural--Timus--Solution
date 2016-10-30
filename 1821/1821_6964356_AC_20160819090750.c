#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
typedef struct _item{
    char name[21];
    char yes;
    int time;
    int atime;
}item;
item a[101];
int cmp1(item *a,item *b){
    return a->atime-b->atime;
}
int cmp2(item *a,item *b){
    return strcmp(a->name,b->name);
}
int main(){
    int n,i,x,y,z,nb=INT_MAX,cnt=0;
    char c1,c2;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s%d%c%d%c%d",a[i].name,&x,&c1,&y,&c2,&z);
        a[i].time=x*600+y*10+z;
        a[i].atime=a[i].time+300*i;
        a[i].yes=0;
    }
    qsort(a,n,sizeof(item),cmp1);
    for(i=0;i<n;i++)if(a[i].time<nb){
        nb=a[i].time;
        a[i].yes=1;
        cnt++;
    }
    qsort(a, n, sizeof(item), cmp2);
    printf("%d\n",cnt);
    for(i=0;i<n;i++)if(a[i].yes)printf("%s\n",a[i].name);
    return 0;
}
