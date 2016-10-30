#include <iostream>
#include <map>
#include <cmath>
using namespace std;
map<int,int> c;
int main(){
    int n,x,l,t;
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        l=-1;
        while(x>=2){
            t=sqrt(x)+1;
            for(int j=2;j<=t;j++)if(x%j==0){
                x/=j;
                if(l!=j){
                    map<int,int>::iterator it=c.find(j);
                    if(it==c.end())c.insert(pair<int,int>(j,1));
                    else it->second++;
                }
                l=j;
                goto nxt;
            }
            if(x>l){
                map<int,int>::iterator it=c.find(x);
                if(it==c.end())c.insert(pair<int,int>(x,1));
                else it->second++;
            }
            break;
        nxt:;
        }
    }
    x=0;
    for(map<int,int>::iterator it=c.begin();it!=c.end();it++)if(it->second>x)x=it->second;
    if(x<3)cout<<x<<endl;
    else cout<<"infinity"<<endl;
    return 0;
}
