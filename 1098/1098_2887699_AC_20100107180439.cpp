#include <stdio.h>
int l[40000]={0},r[40000]={0},s[40000]={0},k[40000]={-1},p=0,c=0;
char in[40000];
void lr(int &t){
     int k=r[t];
     r[t]=l[k];
     l[k]=t;
     s[k]=s[t];
     s[t]=s[l[t]]+s[r[t]]+1;
     t=k;
}
void rr(int &t){
     int k=l[t];
     l[t]=r[k];
     r[k]=t;
     s[k]=s[t];
     s[t]=s[l[t]]+s[r[t]]+1;
     t=k;
}
void maintain(int &t,int f){
     if(t==0)return;
     if(f==0){
       if(s[l[l[t]]]>s[r[t]])rr(t);
       else{
         if(s[r[l[t]]]>s[r[t]]){
           lr(l[t]);
           rr(t);
         }else return;
       }
     }else{
       if(s[r[r[t]]]>s[l[t]])lr(t);
       else{
         if(s[l[r[t]]]>s[l[t]]){
           rr(r[t]);
           lr(t);
         }else return;
       }
     }
     maintain(l[t],0);
     maintain(l[t],1);
     maintain(t,0);
     maintain(t,1);
}
void insert(int &t,int v){
     if(t==0){
       t=v;
       return;
     }
     s[t]++;
     if(k[v]<k[t])insert(l[t],v);
     else insert(r[t],v);
     maintain(t,v>=k[t]);
}
int del(int &t,int v){
    int rtn;
    s[t]--;
    if(v==k[t]||v<k[t]&&l[t]==0||v>k[t]&&r[t]==0){
      rtn=k[t];
      if(l[t]==0||r[t]==0)t=l[t]+r[t];
      else k[t]=del(l[t],k[t]+1);
    }else{
      if(v<k[t])rtn=del(l[t],v);
      else rtn=del(r[t],v);
    }
    return rtn;
}
int select(int t,int v){
    if(s[l[t]]+1==v)return k[t];
    if(v<=s[l[t]])return select(l[t],v);
    return select(r[t],v-s[l[t]]-1);
}
int main(){
    char tc;
    int i,y,at=0,head=0;
    while((tc=getchar())!=EOF){
      if(tc==13||tc==10)continue;
      k[++p]=c;
      in[c++]=tc;
      s[p]=1;
      if(head==0){
        head=p;
        k[p]=0;
      }else insert(head,p);
    }
    while(c>1){
      at=(at+1998)%c;
      c--;
      y=select(head,at+1);
      del(head,y);
    }
    if(in[k[head]]=='?')printf("Yes\n");
    else if(in[k[head]]==' ')printf("No\n");
    else printf("No comments\n");
}
