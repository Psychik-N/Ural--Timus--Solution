#include <stdio.h>
#include <string.h>
int main(){
    char dic[200][20]={0},buf[200]={0},tc;
    int dl[200],l=-1,i,j,s,bl=0,ol=0,w=0;
    while(1){
      scanf("%s\n",dic[++l]);
      if(dic[l][0]=='#')break;
      dl[l]=strlen(dic[l]);
    }
    while((tc=getchar())!=EOF){
      if(tc>='a'&&tc<='z')buf[bl++]=tc;
      else{
        if(bl!=0){
          for(i=0;i<l;i++){
            if(dl[i]!=bl)continue;
            s=0;
            for(j=0;j<bl;j++)if(buf[j]!=dic[i][j])s++;
            if(s==1)for(j=0;j<bl;j++)putchar(dic[i][j]);
            else goto nxt;
            w++;
            goto out;
            nxt:;
          }
          for(j=0;j<bl;j++)putchar(buf[j]);
        }
        out:
        putchar(tc);
        bl=0;
      }
    }
    printf("%d\n",w);
}
