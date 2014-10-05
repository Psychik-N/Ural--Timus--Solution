#include <stdio.h>
#pragma comment(linker,"/STACK:16000000")
int main(){
    int ol=0,n,i,j,bv,bi,a,b;
    long long p[100001];
    long long heap[100001],le=-2000000000;
    int size=0,now,dest;
    long long t;
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d%d",&a,&b);
      t=(long long)b*200000+a;
      now=i;
      while(now>0&&t<heap[(now-1)>>1]){
        heap[now]=heap[(now-1)>>1];
        now=(now-1)>>1;
      }
      heap[now]=t;
    }
    size=n;
    for(i=0;i<n;i++){
      p[i]=heap[0];
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
    for(i=0;i<n;i++){
      if(p[i]%200000>le){
        le=p[i]/200000;
        ol++;
      }
    }
    printf("%d\n",ol);
}
