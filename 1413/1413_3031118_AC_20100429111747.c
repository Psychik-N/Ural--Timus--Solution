#include <stdio.h>
#include <math.h>
int main(){
    int x1=0,x2=0,y1=0,y2=0;
    char c;
    while((c=getchar())!=EOF){
      if(c=='8')y1++;
      if(c=='4')x1--;
      if(c=='6')x1++;
      if(c=='2')y1--;
      if(c=='7'||c=='1')x2--;
      if(c=='9'||c=='3')x2++;
      if(c=='7'||c=='9')y2++;
      if(c=='1'||c=='3')y2--;
      if(c=='0')goto out;
    }
    out:
    printf("%.10lf %.10lf\n",(double)x1+(double)x2*sqrt(2.0)/2,(double)y1+(double)y2*sqrt(2.0)/2);
}
