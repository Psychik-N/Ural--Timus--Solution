#include <stdio.h>
int pc[66000]={0},ps[66000],pe[66000],l[33000]={0};
int min(int a,int b){
if(a<b)return a;
return b;
}
int max(int a,int b){
if(a>b)return a;
return b;
}
int ms(){
    int s=0;
    char c,m=0;
    do{
      c=getchar();
    }while((c!='-')&&(c<48||c>57));
    if(c=='-')m=1;
    else s=c-48;
    while(1){
      c=getchar();
      if(c<48||c>57)break;
      s=s*10+c-48;
    }
    if(m)return -s;
    return s;
}
void mp(int s){
     char b[12];
     int l=0,i,m=0;
     if(s==0){
       putchar(48);
       return;
     }
     if(s<0){
       m=1;
       s=-s;
     }
     while(s){
       b[l]=s%10;
       l++;
       s/=10;
     }
     if(m)putchar('-');
     for(i=l-1;i>=0;i--)putchar(b[i]);
}
void init(int p,int s,int e){
int mid=(s+e)/2;
ps[p]=s;
pe[p]=e;
if(s==e)return;
init(p*2+1,s,mid);
init(p*2+2,mid+1,e);
}
int query(int p,int n){
if(ps[p]==pe[p])return pc[p];
if(n<=pe[p*2+1])return pc[p]+query(p*2+1,n);
return pc[p]+query(p*2+2,n);
}
void add(int p,int s,int e){
if(s==ps[p]&&e==pe[p]){
pc[p]++;
return;
}
if(s<=pe[p*2+1])add(p*2+1,s,min(e,pe[p*2+1]));
if(e>=ps[p*2+2])add(p*2+2,max(ps[p*2+2],s),e);
}
int main(){
int n,i,x,y;
init(0,0,32000);
n=ms();
for(i=0;i<n;i++){
x=ms();
y=ms();
l[query(0,x)]++;
add(0,x,32000);
}
for(i=0;i<n;i++){mp(l[i]);putchar('\n');}
}
