#include <stdio.h>
#include <string.h>
void jf(char *a,char *b,char *c){
int at=0,la=strlen(a),lb=strlen(b),jw;
char t;
while(at<la||at<lb||jw!=0){
t=0;
if(at<la)t+=a[at]-'0';
if(at<lb)t+=b[at]-'0';
if(jw)t++;
if(t>9)jw=1;
else jw=0;
c[at]=t%10+'0';
c[at+1]='0';
at++;
}
}
int main(){
char a[10000]={0},b[10000]={0},r[10000],s[10000],t[10000];
int n,k,i,j;
scanf("%d %d",&n,&k);
a[0]='1';
b[0]=(char)(k-1+'0');
for(i=2;i<=n;i++){
add(a,b,t);
strcpy(s,t);
for(j=1;j<k-1;j++){
add(s,t,r);
strcpy(s,r);
}
strcpy(a,b);
strcpy(b,r);
}
for(i=strlen(b);i>=0;i--)printf("%c",b[i]);
}
