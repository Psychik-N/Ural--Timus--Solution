#include <stdio.h>
#define eps (1e-9)
int trans(char c){
    if(c=='A')return 0;
    if(c=='E')return 1;
    if(c=='F')return 2;
    return 3;
}
int time(char *s){
    int i;
    for(i=0;i<8;i++)s[i]-=48;
    return (int)(s[0]*10+s[1])*3600+(int)(s[3]*10+s[4])*60+(int)(s[6]*10+s[7]);
}
int main(){
    int i,j,t,t1[4],t2[4],z1[4],z2[4],a,b,l,c1[4]={0},c2[4]={0},bt=-1,tr1,tr2;
    char c[5],sa[10],sb[10],in[1010];
    double s1,s2,bv=-1;
    for(i=0;i<4;i++){
      scanf("%s %s %d %s %d\n",c,sa,&a,sb,&b);
      l=trans(c[0]);
      tr1=time(sa);
      tr2=time(sb);
      if(tr1<tr2){
        z1[l]=a;
        z2[l]=b;
        t1[l]=tr1;
        t2[l]=tr2;
      }else{
        z1[l]=b;
        z2[l]=a;
        t1[l]=tr2;
        t2[l]=tr1;
      }
    }
    gets(in);
    l=strlen(in);
    for(i=0;i<l;i++)c1[trans(in[i])]++;
    gets(in);
    l=strlen(in);
    for(i=0;i<l;i++)c2[trans(in[i])]++;
    for(i=7200;i<86400;i++){
      s1=s2=0;
      for(j=0;j<4;j++){
        if(i<t1[j]){
          if(z1[j]>z2[j])s1+=((double)(i-t2[j]+86400)*(z1[j]-z2[j])/(t1[j]-t2[j]+86400)+z2[j])*c1[j];
          else s1+=((double)(t1[j]-i)*(z2[j]-z1[j])/(t1[j]-t2[j]+86400)+z1[j])*c1[j];
        }
        else if(i==t1[j])s1+=(double)z1[j]*c1[j];
        else if(i==t2[j])s1+=(double)z2[j]*c1[j];
        else if(i>t2[j]){
          if(z1[j]>z2[j])s1+=((double)(i-t2[j])*(z1[j]-z2[j])/(t1[j]-t2[j]+86400)+z2[j])*c1[j];
          else s1+=((double)(t1[j]+86400-i)*(z2[j]-z1[j])/(t1[j]-t2[j]+86400)+z1[j])*c1[j];
        }
        else{
          if(z2[j]>z1[j])s1+=((double)(i-t1[j])*(z2[j]-z1[j])/(t2[j]-t1[j])+z1[j])*c1[j];
          else s1+=((double)(t2[j]-i)*(z1[j]-z2[j])/(t2[j]-t1[j])+z2[j])*c1[j];
        }
      }
      for(j=0;j<4;j++){
        if(i<t1[j]){
          if(z1[j]>z2[j])s2+=((double)(i-t2[j]+86400)*(z1[j]-z2[j])/(t1[j]-t2[j]+86400)+z2[j])*c2[j];
          else s2+=((double)(t1[j]-i)*(z2[j]-z1[j])/(t1[j]-t2[j]+86400)+z1[j])*c2[j];
        }
        else if(i==t1[j])s2+=(double)z1[j]*c2[j];
        else if(i==t2[j])s2+=(double)z2[j]*c2[j];
        else if(i>t2[j]){
          if(z1[j]>z2[j])s2+=((double)(i-t2[j])*(z1[j]-z2[j])/(t1[j]-t2[j]+86400)+z2[j])*c2[j];
          else s2+=((double)(t1[j]+86400-i)*(z2[j]-z1[j])/(t1[j]-t2[j]+86400)+z1[j])*c2[j];
        }
        else{
          if(z2[j]>z1[j])s2+=((double)(i-t1[j])*(z2[j]-z1[j])/(t2[j]-t1[j])+z1[j])*c2[j];
          else s2+=((double)(t2[j]-i)*(z1[j]-z2[j])/(t2[j]-t1[j])+z2[j])*c2[j];
        }
      }
      if(s1-s2<eps)continue;
      if(s1-s2-eps>bv){
        bv=s1-s2;
        bt=i;
      }
    }
    if(bt==-1)puts("We can't win!");
    else{
      l=bt/3600;
      if(l<10)printf("0%d:",l);
      else printf("%d:",l);
      l=(bt%3600)/60;
      if(l<10)printf("0%d:",l);
      else printf("%d:",l);
      l=bt%60;
      if(l<10)printf("0%d",l);
      else printf("%d",l);
      printf("\n%.2lf",bv);
    }
}
