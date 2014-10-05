int main(){
    int i,j,k,l=0;
    char a[5][5][5],b[5][5],r[5][5],ob[20]={0};
    for(i=0;i<4;i++)gets(a[0][i]);
    for(i=0;i<4;i++)gets(b[i]);
    for(i=0;i<4;i++){
      for(j=0;j<4;j++)for(k=0;k<4;k++)if(a[i][j][k]=='X')ob[l++]=b[j][k];
      for(j=0;j<4;j++)for(k=0;k<4;k++)a[i+1][j][k]=a[i][3-k][j];
    }
    puts(ob);
}
