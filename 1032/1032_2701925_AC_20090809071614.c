#include <stdio.h>
#include <stdlib.h>
int in[10001];
void out(int s,int e){
     int i,n=e-s+1,*heap,size=0,now,t,dest;
     printf("%d\n",e-s+1);
     heap=malloc(sizeof(int)*n);
     for(i=0;i<n;i++){
       t=in[s+i];
       now=i;
       while(now>0&&t<heap[(now-1)>>1]){
         heap[now]=heap[(now-1)>>1];
         now=(now-1)>>1;
       }
       heap[now]=t;
     }
     size=n;
     for(i=0;i<n;i++){
       printf("%d\n",heap[0]);
       size--;
       now=0;
       t=1;
       while((now<<1)+1<size&&t){
         t=0;
         if((now<<1)+2==size)
           dest=now*2+1;
         else if(heap[(now<<1)+1]<heap[(now<<1)+2])
           dest=(now<<1)+1;
         else
           dest=(now<<1)+2;
         if(heap[size]>heap[dest]){
           heap[now]=heap[dest];
           now=dest;
           t=1;
         }
       }
       heap[now]=heap[size];
     }
     exit(0);
}
int main(){
    int i,n,m[10001],y[10000]={0};
    m[0]=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
      scanf("%d",&in[i]);
      m[i]=(m[i-1]+in[i])%n;
      if(m[i]==0)out(1,i);
      if(y[m[i]]!=0)out(y[m[i]]+1,i);
      y[m[i]]=i;
    }
    puts("0");
}
