#include <stdio.h>
int main(){
    int n,x,y,v;
    scanf("%d%d%d",&n,&x,&y);
    
    v=0;
    if(x>1){
        v++;
        if(y!=1)v++;
        if(y!=n)v++;
    }
    if(x<n){
        v++;
        if(y!=1)v++;
        if(y!=n)v++;
    }
    if(y!=1)v++;
    if(y!=n)v++;
    printf("King: %d\n",v);
    
    v=0;
    if(x+2<=n&&y+1<=n)v++;
    if(x+2<=n&&y-1>=1)v++;
    if(x+1<=n&&y+2<=n)v++;
    if(x+1<=n&&y-2>=1)v++;
    if(x-1>=1&&y+2<=n)v++;
    if(x-1>=1&&y-2>=1)v++;
    if(x-2>=1&&y+1<=n)v++;
    if(x-2>=1&&y-1>=1)v++;
    printf("Knight: %d\n",v);
    
    v=(x+y<=n+1?x+y-2:n-y+n-x)+(y<=x?n-x+y-1:n-y+x-1);
    printf("Bishop: %d\n",v);
    
    printf("Rook: %d\n",n*2-2);
    
    printf("Queen: %d\n",v+n*2-2);
    return 0;
}
