#include <stdio.h>
int dx[53]={0,3,4,5,6,7,8,8,9,9,10,12,12,12,12,14,15,15,15,16,16,18,20,20,20,21,21,24,24,24,24,24,27,28,28,30,30,32,33,35,36,36,36,40,40,40,42,44,45,45,48,48,48};
int dy[53]={0,4,3,12,8,24,6,15,12,40,24,5,9,16,35,48,8,20,36,12,30,24,15,21,48,20,28,7,10,18,32,45,36,21,45,16,40,24,44,12,15,27,48,9,30,42,40,33,24,28,14,20,36};
int main(){
    char a[51][51],ma[51][51];
    int m,n,i,j,k,ia,ib,t;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
      scanf("%s",a[i]);
    for(i=0;i<n;i++){
      for(j=0;j<m;j++){
        scanf("%d",&t);
        if(t%2==0)continue;
        for(ia=0;ia<51;ia++)
          for(ib=0;ib<51;ib++)
            ma[ia][ib]=0;
        for(k=0;k<m;k++)
          if(ma[i][k]==0){
            a[i][k]=(a[i][k]=='W'?'B':'W');
            ma[i][k]=1;
          }
        for(k=0;k<n;k++)
          if(ma[k][j]==0){
            a[k][j]=(a[k][j]=='W'?'B':'W');
            ma[k][j]=1;
          }
        for(k=0;k<53;k++){
          if(j+dx[k]<m&&i+dy[k]<n)
            if(ma[i+dy[k]][j+dx[k]]==0){
              a[i+dy[k]][j+dx[k]]=(a[i+dy[k]][j+dx[k]]=='W'?'B':'W');
              ma[i+dy[k]][j+dx[k]]=1;
            }
          if(j-dx[k]>=0&&i+dy[k]<n)
            if(ma[i+dy[k]][j-dx[k]]==0){
              a[i+dy[k]][j-dx[k]]=(a[i+dy[k]][j-dx[k]]=='W'?'B':'W');
              ma[i+dy[k]][j-dx[k]]=1;
            }
          if(j+dx[k]<m&&i-dy[k]>=0)
            if(ma[i-dy[k]][j+dx[k]]==0){
              a[i-dy[k]][j+dx[k]]=(a[i-dy[k]][j+dx[k]]=='W'?'B':'W');
              ma[i-dy[k]][j+dx[k]]=1;
            }
          if(j-dx[k]>=0&&i-dy[k]>=0)
            if(ma[i-dy[k]][j-dx[k]]==0){
              a[i-dy[k]][j-dx[k]]=(a[i-dy[k]][j-dx[k]]=='W'?'B':'W');
              ma[i-dy[k]][j-dx[k]]=1;
            }
        }
      }
    }
    for(i=0;i<n;i++){
      for(j=0;j<m;j++)
        printf("%c",a[i][j]);
      printf("\n");
    }
}
