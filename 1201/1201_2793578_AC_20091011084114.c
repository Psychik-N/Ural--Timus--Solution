#include <stdio.h>
const b[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
    int d=1,m,y,l[7],i,j,wd,c=6,rd,md;
    char out[7][100]={"mon","tue","wed","thu","fri","sat","sun"};
    for(i=0;i<7;i++)for(j=3;j<100;j++)out[i][j]=' ';
    for(i=0;i<7;i++)l[i]=3;
    scanf("%d%d%d",&rd,&m,&y);
    if(m<3)wd=(y-1)%100+((y-1)%100)/4+(y-1)/100/4-2*((y-1)/100)+26*(m+1+12)/10+d-1;
    else wd=y%100+(y%100)/4+y/100/4-2*(y/100)+26*(m+1)/10+d-1;
    wd%=7;
    if(wd<0)wd+=7;
    if(wd==0)wd=7;
    wd--;
    md=b[m];
    if((y%4==0&&y%100!=0)||(y%400==0)&&(m==2))md++;
    for(i=1;i<=md;i++){
      out[wd][c]=i%10+'0';
      if(i>9)out[wd][c-1]=i/10+'0';
      l[wd]=c+1;
      if(i==rd){
        out[wd][c-2]='[';
        out[wd][c+1]=']';
        l[wd]=c+2;
      }
      wd++;
      if(wd==7){
        wd=0;
        c+=5;
      }
    }
    for(i=0;i<7;i++){
      for(j=0;j<l[i];j++)putchar(out[i][j]);
      putchar('\n');
    }
}
