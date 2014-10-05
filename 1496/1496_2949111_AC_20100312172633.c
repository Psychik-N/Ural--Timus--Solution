#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b){
    return strcmp((char*)a,(char*)b);
}
int main(){
    int n,i,c=0;
    char a[110][35],lst[35]="2539forever";
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%s",a[i]);
    qsort(a,n,35,cmp);
    strcpy(a[n],"zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");
    n++;
    for(i=0;i<n;i++){
      if(strcmp(lst,a[i])){
        if(c>1)printf("%s\n",lst);
        strcpy(lst,a[i]);
        c=1;
      }else c++;
    }
}
