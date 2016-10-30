#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s[310][23],l[310][310]={0};
int sl=0;
int cmp(int *a,int *b){
    return strcmp(s[*a],s[*b]);
}
int main(){
    char ts[23];
    int n,i,j,d[310],a,b,c,p,k,px[310];
    scanf("%d",&n);
    for(i=0;i<n;i++){
      for(j=0;j<3;j++){
        p=-1;
        scanf("%s",ts);
        for(k=0;k<sl;k++)
          if(strcmp(ts,s[k])==0){
            p=k;
            break;
          }
        if(p==-1){
          d[p=sl]=2333333;
          strcpy(s[sl++],ts);
        }
        if(j==0)a=p;
        if(j==1)b=p;
        if(j==2)c=p;
      }
      l[a][b]=l[b][a]=l[a][c]=l[c][a]=l[b][c]=l[c][b]=1;
    }
    for(i=0;i<sl;i++)
      if(strcmp("Isenbaev",s[i])==0)break;
    d[i]=0;
    for(i=0;i<sl;i++)
      for(j=0;j<sl;j++){
        if(d[j]>=2333333)continue;
        for(k=0;k<sl;k++){
          if(l[j][k]==0)continue;
          if(d[j]+1<d[k])d[k]=d[j]+1;
        }
      }
    for(i=0;i<310;i++)px[i]=i;
    qsort(px,sl,sizeof(int),cmp);
    for(i=0;i<sl;i++)
      if(d[px[i]]<10000)printf("%s %d\n",s[px[i]],d[px[i]]);
      else printf("%s undefined\n",s[px[i]]);
    return 0;
}
