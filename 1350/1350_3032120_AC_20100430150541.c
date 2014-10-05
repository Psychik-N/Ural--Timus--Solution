#include <stdio.h>
#include <string.h>
char al[110][50],tn[50];
int main(){
    int n,m,k,i,j,a,l,in[110]={0},out[110]={0},an;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%s",tn);
    scanf("%d %d",&k,&an);
    for(i=0;i<an;i++)scanf("%s",al[i]);
    for(i=0;i<k;i++){
      scanf("%d",&l);
      for(j=0;j<l;j++){
        scanf("%s",tn);
        for(a=0;a<an;a++)if(strcmp(tn,al[a])==0){
          in[i]=1;
          goto nxt;
        }
        out[i]++;
        nxt:;
      }
    }
    scanf("%d",&m);
    for(i=0;i<k;i++){
      if(out[i]==0)printf("YES\n");
      else if(out[i]>n-m-an)printf("NO\n");
      else printf("MAYBE\n");
    }
}
