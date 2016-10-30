#include<fstream>
using namespace std;
ifstream cin("1002.in");
ofstream cout("1002.out");

int len,n,from[101][2];
char p[]="22233344115566070778889990",pin[100],w[50000][50],sum[]="3233222333";
double log[]={0,0,0.301029996,0.477121255},dp[101],yjd[50000];

void out(int o){
     int i;
     if(o==0)return;
     out(from[o][0]);
     for(i=0;i<strlen(w[from[o][1]]);i++)cout<<w[from[o][1]][i];
     cout<<" ";
}



int main(){
    int i,j,k;
    while(1){
        cin>>pin;
        if(pin[0]=='-'){
            system("pause");
            return 0;
        }
        len=strlen(pin);
        cin>>n;
        for(i=0;i<n;i++){
            cin>>w[i];
            yjd[i]=0;
            for(j=0;j<strlen(w[i]);j++){
                yjd[i]+=(double)  log[   (int)(sum[  (int)(p[w[i][j]-97])-48  ]  )-48];
            }
        }
        for(i=0;i<=len;i++){
            from[i][0]=-1;
            from[i][1]=-1;
            dp[i]=2000000000;
        }
        from[0][0]=0;
        from[0][1]=0;
        dp[0]=0;
        for(i=0;i<len;i++){
            if(dp[i]==2000000000)continue;
            for(j=0;j<n;j++){
                if(i+strlen(w[j])>len)continue;
                int flag=1;
                for(k=0;k<strlen(w[j]);k++){
                    if(p[w[j][k]-97]!=pin[i+k]){
                        flag=0;
                        break;
                    }
                }
                if(flag==1){
                    if(dp[i]+yjd[j]<=dp[i+strlen(w[j])]){
                        dp[i+strlen(w[j])]=dp[i]+yjd[j];
                        from[i+strlen(w[j])][0]=i;
                        from[i+strlen(w[j])][1]=j;
                    }
                }
            }
        }
        if(dp[len]==2000000000 ){
            cout<<"No solution.\n";
        }else{
            out(len);
            cout<<"\n";
        }
    }
    
}
