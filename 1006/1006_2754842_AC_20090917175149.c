#include <stdio.h>
int main(){
    unsigned char in[25][55];
    int i,j,k,h,cll=0,cl[21000][4],s,ol=0,o[2000][3];
    int *t;
    for(i=0;i<20;i++)scanf("%s",in[i]);
    for(i=0;i<19;i++){
      for(j=0;j<49;j++){
        for(k=2;k<=20;k++){
          if(i+k>20||j+k>50)break;
          for(h=j;h<j+k;h++)
            if(in[i][h]==(unsigned char)46||in[i+k-1][h]==(unsigned char)46)goto nxt;
          for(h=i;h<i+k;h++)
            if(in[h][j]==(unsigned char)46||in[h][j+k-1]==(unsigned char)46)goto nxt;
          cl[cll][0]=i;
          cl[cll][1]=j;
          cl[cll][2]=k;
          cl[cll][3]=0;
          cll++;
          nxt:;
        }
      }
    }
    start:
    for(i=0;i<cll;i++){
      t=cl[i];
      if(t[3])continue;
      for(j=t[1];j<t[1]+t[2];j++)
        if(in[t[0]][j]!='*'||in[t[0]+t[2]-1][j]!='*')goto ok;
      for(j=t[0];j<t[0]+t[2];j++)
        if(in[j][t[1]]!='*'||in[j][t[1]+t[2]-1]!='*')goto ok;
      t[3]=1;
      continue;
      ok:
      if(in[t[0]][t[1]]==(unsigned char)218||in[t[0]][t[1]]=='*'){
        if(in[t[0]][t[1]+t[2]-1]==(unsigned char)191||in[t[0]][t[1]+t[2]-1]=='*'){
          if(in[t[0]+t[2]-1][t[1]]==(unsigned char)192||in[t[0]+t[2]-1][t[1]]=='*'){
            if(in[t[0]+t[2]-1][t[1]+t[2]-1]==(unsigned char)217||in[t[0]+t[2]-1][t[1]+t[2]-1]=='*'){
              for(j=t[1]+1;j<t[1]+t[2]-1;j++)
                if((in[t[0]][j]!=(unsigned char)196&&in[t[0]][j]!='*')||(in[t[0]+t[2]-1][j]!=(unsigned char)196&&in[t[0]+t[2]-1][j]!='*'))goto nxt2;
              for(j=t[0]+1;j<t[0]+t[2]-1;j++)
                if((in[j][t[1]]!=(unsigned char)179&&in[j][t[1]]!='*')||(in[j][t[1]+t[2]-1]!=(unsigned char)179&&in[j][t[1]+t[2]-1]!='*'))goto nxt2;
            }else goto nxt2;
          }else goto nxt2;
        }else goto nxt2;
      }else goto nxt2;
              for(j=t[1];j<t[1]+t[2];j++)
                in[t[0]][j]=in[t[0]+t[2]-1][j]='*';
              for(j=t[0];j<t[0]+t[2];j++)
                in[j][t[1]]=in[j][t[1]+t[2]-1]='*';
      t[3]=1;
      o[ol][0]=t[1];
      o[ol][1]=t[0];
      o[ol][2]=t[2];
      ol++;
      goto start;
      nxt2:;
    }
    printf("%d\n",ol);
    for(i=ol-1;i>=0;i--)printf("%d %d %d\n",o[i][0],o[i][1],o[i][2]);
}
