/* We're going to start working on Volume 2.    *
 * God bless us.                                *
 *           Weihongxuejia 2009-8-9             */
#include <stdio.h>
int main(){
    int sz[150001][2],n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d%d",&sz[i][0],&sz[i][1]);
    for(i=100;i>=0;i--)
      for(j=0;j<n;j++)
        if(sz[j][1]==i)
          printf("%d %d\n",sz[j][0],sz[j][1]);
}
