#include <stdio.h>
int main(){
    int a,b,c,d,e,f,g,i,l,r;
    scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g);
    r=(a*10+b*50+c*100+d*500+e*1000+f*5000)/g;
    if(a)l=(int)(((a-1)*10+b*50+c*100+d*500+e*1000+f*5000)/(double)g+1.0);
    else if(b)l=(int)((a*10+(b-1)*50+c*100+d*500+e*1000+f*5000)/(double)g+1.0);
    else if(c)l=(int)((a*10+b*50+(c-1)*100+d*500+e*1000+f*5000)/(double)g+1.0);
    else if(d)l=(int)((a*10+b*50+c*100+(d-1)*500+e*1000+f*5000)/(double)g+1.0);
    else if(e)l=(int)((a*10+b*50+c*100+d*500+(e-1)*1000+f*5000)/(double)g+1.0);
    else l=(int)(((a)*10+b*50+c*100+d*500+e*1000+(f-1)*5000)/(double)g+1.0);
    printf("%d\n",r-l+1);
    for(i=l;i<=r;i++)printf("%d ",i);
}
