#include<iostream>
using namespace std;
void f1(int n);
void f2(int a,int b);

int main(){
    int n;
    cin>>n;
    f1(n);
    system("pause");
}

void f1(int n){
     if(n==1){
              int ta,tb;
              cin>>ta>>tb;
              cout<<ta<<" "<<tb<<"\n.";
              return;
     }
     int i,m[11][11]={0},x,y,a,b,j,s=0,te=0;
     for(i=1;i<=n;i++){
         cin>>a>>b;
         m[a][b]=1;
     }
     for(i=1;i<=10;i++){
         for(j=1;j<=10;j++){
             if(m[i][j]==1){
                 x=i;
                 y=j;
                 te=1;
                 break;
             }
         }
         if(te==1)break;
     }
     cout<<x<<" "<<y<<"\n";
     int list[101][2][2]={0},qlen[2]={1},on=0,f[11][11]={0},dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
     list[1][0][0]=x;
     list[1][1][0]=y;
     char d[4]={'R','T','L','B'};
     while((qlen[on])!=0){
         qlen[!on]=0;
         for(i=1;i<=qlen[on];i++){
             x=list[i][0][on];
             y=list[i][1][on];
             for(j=0;j<4;j++){
                 if(x+dx[j]>=1&&x+dx[j]<=10&&y+dy[j]>=1&&y+dy[j]<=10){
                     if(f[x+dx[j]][y+dy[j]]==0&&m[x+dx[j]][y+dy[j]]==1){
                         qlen[!on]++;
                         list[qlen[!on]][0][!on]=x+dx[j];
                         list[qlen[!on]][1][!on]=y+dy[j];
                         cout<<d[j];
                         f[x+dx[j]][y+dy[j]]=1;
                     }
                 }
             }
             f[x][y]=1;
             s++;
             if(s!=n){
                 cout<<",\n";
             }else{
                 cout<<".";
                 return;
             }
         }
         on=!on;
     }
}
         
         