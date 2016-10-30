#include <stdio.h>
char map[210][210];
int main(){
    int minx=101,miny=101,maxx=-101,maxy=-101,n,x,y,i,j;
    for(i=0;i<210;i++)for(j=0;j<210;j++)map[i][j]='.';
    for(i=0;i<210;i++)map[105][i]='-';
    for(i=0;i<210;i++)map[i][105]='|';
    map[105][105]='+';
    scanf("%d",&n);
    while(n-->0){
        scanf("%d%d",&x,&y);
        if(x<minx)minx=x;
        if(x>maxx)maxx=x;
        if(y<miny)miny=y;
        if(y>maxy)maxy=y;
        map[105-y][x+105]='*';
    }
    for(i=105-maxy;i<=105-miny;i++){
        for(j=minx+105;j<=maxx+105;j++)printf("%c",map[i][j]);
        printf("\n");
    }
    return 0;
}
