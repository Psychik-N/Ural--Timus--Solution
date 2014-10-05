#include <stdio.h>
#include <string.h>
char reg[26]={0};
int calc(char *in){
    int l,i,sl=0,hl=0;
    char stk[251]={0},hz[251]={0};
    l=strlen(in);
    for(i=0;i<l;i++){
      if(in[i]>='A'&&in[i]<='Z'){
        hz[hl]=reg[in[i]-'A']+'0';
        hl++;
      }else if(in[i]=='('){
        stk[sl]=in[i];
        sl++;
      }else if(in[i]==')'){
        sl--;
        while(stk[sl]!='('){
          hz[hl]=stk[sl];
          hl++;
          sl--;
        }
      }else if(in[i]=='0'||in[i]=='1'){
        hz[hl]=in[i];
        hl++;
      }else if(in[i]=='!'){/*
        sl--;
        while((stk[sl]=='!')&&sl>=0){
          hz[hl]=stk[sl];
          hl++;
          sl--;
        }
        sl++;*/
        stk[sl]=in[i];
        sl++;
      }else if(in[i]=='&'){
        sl--;
        while((stk[sl]=='!'||stk[sl]=='&')&&sl>=0){
          hz[hl]=stk[sl];
          hl++;
          sl--;
        }
        sl++;
        stk[sl]=in[i];
        sl++;
      }else if(in[i]=='|'){
        sl--;
        while((stk[sl]=='!'||stk[sl]=='&'||stk[sl]=='|')&&sl>=0){
          hz[hl]=stk[sl];
          hl++;
          sl--;
        }
        sl++;
        stk[sl]=in[i];
        sl++;
      }
    }
    for(i=sl-1;i>=0;i--){
      hz[hl]=stk[i];
      hl++;
    }
    sl=0;
    for(i=0;i<hl;i++){
      if(hz[i]=='0'||hz[i]=='1'){
        stk[sl]=hz[i];
        sl++;
      }else{
        if(hz[i]=='!')
          stk[sl-2]=(!(stk[sl-1]-48))+48;
        else if(hz[i]=='&')
          stk[sl-2]=((stk[sl-2]-48)&(stk[sl-1]-48))+48;
        else
          stk[sl-2]=((stk[sl-2]-48)|(stk[sl-1]-48))+48;
        sl--;
      }
    }
    return stk[0]-'0';
}
int main(){
    char re[260]={0},in[260]={0},g[210][210]={0},c;
    int rl=0,il,ip=0,n,m,k,dir=0,mx=0,my=0,t1,t2,i;
    gets(in);
    il=strlen(in);
    while(ip<il){
      if(in[ip]=='N'&&in[ip+1]=='O'&&in[ip+2]=='T'){
        re[rl+0]='1';
        re[rl+1]='!';
        rl+=2;
        ip+=3;
      }else if(in[ip]=='A'&&in[ip+1]=='N'&&in[ip+2]=='D'){
        re[rl]='&';
        rl++;
        ip+=3;
      }else if(in[ip]=='O'&&in[ip+1]=='R'){
        re[rl]='|';
        rl++;
        ip+=2;
      }else if(in[ip]=='T'&&in[ip+1]=='R'&&in[ip+2]=='U'&&in[ip+3]=='E'){
        re[rl]='1';
        rl++;
        ip+=4;
      }else if(in[ip]=='F'&&in[ip+1]=='A'&&in[ip+2]=='L'&&in[ip+3]=='S'&&in[ip+4]=='E'){
        re[rl]='0';
        rl++;
        ip+=5;
      }else if(in[ip]!=' '){
        re[rl]=in[ip];
        rl++;
        ip++;
      }else{
        ip++;
      }
    }
    scanf("%d %d %d",&n,&m,&k);
    for(i=0;i<m;i++){
      scanf("%d %d",&t1,&t2);
      g[t1+100][t2+100]=1;
    }
    for(i=0;i<k;i++){
      scanf("%d %d %c",&t1,&t2,&c);
      g[t1+100][t2+100]=c;
    }
    puts("0 0");
    while(1){
      if(dir==0)mx++;
      else if(dir==1)my--;
      else if(dir==2)mx--;
      else my++;
      if(mx>n||mx<-n||my>n||my<-n)break;
      printf("%d %d\n",mx,my);
      if(g[mx+100][my+100]==0);
      else if(g[mx+100][my+100]==1){
        if(calc(re))dir++;
        else dir--;
        if(dir==-1)dir=3;
        if(dir==4)dir=0;
      }
      else reg[g[mx+100][my+100]-'A']=!reg[g[mx+100][my+100]-'A'];
    }
}
