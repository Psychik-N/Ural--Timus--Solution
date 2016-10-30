#include <iostream>
#include <queue>
using namespace std;
int main(){
    cin.sync_with_stdio(false);
    deque<int> q;
    int n,t,i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>t;
        if(t>0){
            q.push_front(t);
        }else if(t<0){
            cout<<q.front()<<'\n';
            q.pop_front();
        }else{
            //deque<int>::iterator it=q.begin(),l=q.end();
            if(q.size()<=n-i)q.insert(q.begin(), q.begin(), q.end());
        }
    }
    return 0;
}
