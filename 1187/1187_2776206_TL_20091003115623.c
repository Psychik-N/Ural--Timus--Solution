#include <stdio.h>
#include <string.h>
char caps[110],qt[110][4]={0},qc[110][110]={0},qd[110][110][45]={0},zm[110][110],hd[10010][110];
int qs=0,ql[110]={0},dy[110][256],rs=0,count[110][110],pc[110][110],pc2[110][110],pt[110],pt2[110];
int main(){
    int c,l,i,j,k,ta,tb,tot1[110],tot2[110],s1,s2;
    char in[110];
    gets(caps);
    while(1){
      gets(in);
      if(in[0]=='#')break;
      if(in[0]==' '){
        l=strlen(in);
        for(i=3;i<l;i++)qd[qs-1][ql[qs-1]][i-3]=in[i];
        dy[qs-1][in[1]]=ql[qs-1];
        zm[qs-1][ql[qs-1]]=in[1];
        ql[qs-1]++;
      }else{
        l=strlen(in);
        for(i=0;i<3;i++)qt[qs][i]=in[i];
        for(i=4;i<l;i++)qc[qs][i-4]=in[i];
        qs++;
      }
    }
    while(1){
      gets(in);
      if(in[0]=='#')break;
      strcpy(hd[rs],in);
      rs++;
    }
    while(1){
      gets(in);
      if(in[0]=='#')break;
      l=strlen(in);
      for(i=0;i<qs;i++)if(qt[i][0]==in[0]&&qt[i][1]==in[1]&&qt[i][2]==in[2])break;
      ta=i;
      for(i=0;i<qs;i++)if(qt[i][0]==in[4]&&qt[i][1]==in[5]&&qt[i][2]==in[6])break;
      tb=i;
      printf("%s - ",caps);
      for(i=8;i<l;i++)putchar(in[i]);
      putchar('\n');
      printf("%s %s\n",qt[ta],qc[ta]);
      for(i=0;i<ql[ta];i++)printf(" %c %s\n",zm[ta][i],qd[ta][i]);
      printf("%s %s\n",qt[tb],qc[tb]);
      for(i=0;i<ql[tb];i++)printf(" %c %s\n",zm[tb][i],qd[tb][i]);
      putchar('\n');
      for(i=0;i<110;i++)for(j=0;j<110;j++)count[i][j]=0;
      for(i=0;i<rs;i++)count[dy[ta][hd[i][ta]]][dy[tb][hd[i][tb]]]++;
      for(i=0;i<110;i++)tot1[i]=tot2[i]=0;
      for(i=0;i<ql[ta];i++)for(j=0;j<ql[tb];j++)tot1[i]+=count[i][j];
      for(i=0;i<ql[tb];i++)for(j=0;j<ql[ta];j++)tot2[i]+=count[j][i];
      for(i=0;i<6;i++)putchar(' ');
      for(i=0;i<ql[tb];i++)printf(" %s:%c",qt[tb],zm[tb][i]);
      puts(" TOTAL");
      s2=0;
      for(i=0;i<ql[ta];i++){
        s1=0;
        if(tot1[i]!=0){
          for(j=0;j<ql[tb];j++)s1+=(pc[i][j]=count[i][j]*100/tot1[i]);
          k=ql[tb];
          for(j=0;j<100-s1;j++){
            while(1){
              k--;
          if(k<0)while(1);
              if(count[i][k]!=0&&(count[i][k]*100)%tot1[i]!=0){
                pc[i][k]++;
                break;
              }
            }
          }
        }
      }
      for(i=0;i<ql[tb];i++){
        s1=0;
        if(tot2[i]!=0){
          for(j=0;j<ql[ta];j++)s1+=(pc2[j][i]=count[j][i]*100/tot2[i]);
          k=ql[ta];
          for(j=0;j<100-s1;j++){
            while(1){
              k--;
          if(k<0)while(1);
              if(count[k][i]!=0&&(count[k][i]*100)%tot2[i]!=0){
                pc2[k][i]++;
                break;
              }
            }
          }
        }
      }
      for(i=0;i<ql[ta];i++)s2+=(pt[i]=tot1[i]*100/rs);
      k=ql[tb];
      for(j=0;j<100-s2;j++){
        while(1){
          k--;
          if(k<0)while(1);
          if(tot1[k]!=0&&(tot1[k]*100)%rs!=0){
            pt[k]++;
            break;
          }
        }
      }
      s1=0;
      for(j=0;j<ql[tb];j++)s1+=(pt2[j]=tot2[j]*100/rs);
      k=ql[ta];
      for(j=0;j<100-s1;j++){
        while(1){
          k--;
          if(k<0)while(1);
          if(tot2[k]!=0&&(tot2[k]*100)%rs!=0){
            pt2[k]++;
            break;
          }
        }
      }
      for(i=0;i<ql[ta];i++){
        printf(" %s:%c",qt[ta],zm[ta][i]);
        for(j=0;j<ql[tb];j++)printf("%6d",count[i][j]);
        printf("%6d\n",tot1[i]);
        for(j=0;j<6;j++)putchar(' ');
        for(j=0;j<ql[tb];j++){
          if(tot1[i]==0)printf("     -");
          else printf("%5d%c",pc[i][j],'%');
        }
        if(tot1[i]==0)puts("     -");
        else printf("  100%c\n",'%');
        for(j=0;j<6;j++)putchar(' ');
        for(j=0;j<ql[tb];j++){
          if(tot2[j]==0)printf("     -");
          else printf("%5d%c",pc2[i][j],'%');
        }
        printf("%5d%c\n",pt[i],'%');
      }
      printf(" TOTAL");
      for(j=0;j<ql[tb];j++)printf("%6d",tot2[j]);
      printf("%6d\n",rs);
      for(j=0;j<6;j++)putchar(' ');
      for(j=0;j<ql[tb];j++)printf("%5d%c",pt2[j],'%');
      printf("  100%c\n",'%');
      for(j=0;j<6;j++)putchar(' ');
      for(j=0;j<ql[tb];j++){
        if(tot2[j]==0)printf("     -");
        else printf("  100%c",'%');
      }
      printf("  100%c\n\n",'%');
    }
}
