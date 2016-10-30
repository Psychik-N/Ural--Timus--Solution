#include<iostream>
using namespace std;
//ifstream cin("1003.in");
//ofstream cout("1003.out");
int main(){
  int e[50000][3],s,n,i,x,y,tc,fx,fy,j,cx,cy,sc,te,next,l[15001],nt;
  char c[10];
  for(i=0;i<=15000;i++)e[i][0]=i;
  while(1){
    cin>>s;
    if(s==-1)break;
    for(i=0;i<=15000;i++){
      e[i][1]=-1;
      e[i][2]=-1;
      l[i]=i;
    }
    te=15001;
    cin>>n;
    sc=1;
    for(i=1;i<=n;i+=1){
      cin>>x>>y>>c;
      if(c[0]=='o')tc=0;
      else tc=1;
      fx=0;
      fy=0;
      if((x==y&&tc==1)||x>s||y>s){
        cout<<i-1<<endl;
        goto out;
      }
      for(j=0;j<sc;j++){
        next=e[j][1];
        while(next!=-1){
          if(e[next][0]==x-1){
            fx=1;
            cx=e[next][1];
            nt=next;
            while(e[nt][2]!=-1){
              nt=e[nt][2];
            }
            cx=nt;
          }else if(e[next][0]==y){
            fy=1;
            cy=e[next][1];
            nt=next;
            while(e[nt][2]!=-1){
              nt=e[nt][2];
            }
            cy=nt;
          }else{
          }
          next=e[next][1];
        }
      }
      if(fx==1&&fy==1){
        if(cx/2==cy/2){
          if((cx-cy)*(cx-cy)==tc){
          }
          else{
            cout<<i-1<<endl;
            goto out;
          }
        }
        else{
          if(tc==0){
          }
          else{
            if(cx%2==0)cx++;
            else cx--;
            e[l[cx]][1]=e[cy][1];
            l[cx]=l[cy];
            e[cy][1]=-1;
            e[cy][2]=e[cx][2];
          }
        }
      }else if(fx==1){
        if(tc==0){}
        else{
          if(cx%2==0)cx++;
          else cx--;
        }
        if(e[cx][1]==-1)l[cx]=te;
        e[te][0]=y;
        e[te][1]=e[cx][1];
        e[cx][1]=te;
        e[te][2]=cx;
        te++;
      }else if(fy==1){
        if(tc==0){}
        else{
          if(cy%2==0)cy++;
          else cy--;
        }
        if(e[cy][1]==-1)l[cy]=te;
        e[te][0]=x-1;
        e[te][1]=e[cy][1];
        e[cy][1]=te;
        e[te][2]=cy;
        te++;
      }else{
        if(sc%2==1)sc++;
        if(e[sc][1]==-1)l[sc]=te;
        e[te][0]=x-1;
        e[te][1]=e[sc][1];
        e[sc][1]=te;
        e[te][2]=sc;
        te++;
        if(tc==1)sc++;
        if(e[sc][1]==-1)l[sc]=te;
        e[te][0]=y;
        e[te][1]=e[sc][1];
        e[sc][1]=te;
        e[te][2]=sc;
        te++;
        sc++;
      }
    }
    cout<<n<<endl;
    out:;
    for(i=i+1;i<=n;i++){
      cin>>x>>y>>c;
    }
  }
}

