#include <stdio.h>
#include <string.h>
char u[101][32],p[101][32];
int ul=0;
char li[101]={0};
int main(){
  int n,i,id;
  char s1[32],s2[32],s3[32];
  scanf("%d",&n);
  while(n--){
    scanf("%s %s",s1,s2);
    id=-1;
    for(i=0;i<ul;i++)if(strcmp(u[i],s2)==0)id=i;
    if(strcmp(s1,"register")==0){
      scanf("%s",s3);
      if(id!=-1){puts("fail: user already exists");continue;}
      strcpy(u[ul],s2);
      strcpy(p[ul],s3);
      ul++;
      puts("success: new user added");
    }else if(strcmp(s1,"login")==0){
      scanf("%s",s3);
      if(id==-1)puts("fail: no such user");
      else if(strcmp(s3,p[id])==0){puts(li[id]==1?"fail: already logged in":"success: user logged in");li[id]=1;}
      else puts("fail: incorrect password");
    }else{
      if(id==-1)puts("fail: no such user");
      else if(li[id]==0)puts("fail: already logged out");
      else{puts("success: user logged out");li[id]=0;}
    }
  }
  return 0;
}