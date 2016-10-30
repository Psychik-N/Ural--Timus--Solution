#include <iostream>
#include <queue>
using namespace std;
int main(){
    deque<int> q;
    int n,t,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&t);
        if(t>0){
            q.push_front(t);
            if(q.size()>n-i)q.pop_back();
        }else if(t<0){
            printf("%d\n",q.front());
            q.pop_front();
        }else{
            deque<int>::iterator it=q.begin(),l=q.end();
            while(it!=l&&q.size()<=n-i){
                q.push_back(*it);
                it++;
            }
        }
    }
    return 0;
}
