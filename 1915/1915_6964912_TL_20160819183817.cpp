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
        }else if(t<0){
            printf("%d\n",q.front());
            q.pop_front();
        }else{
            //deque<int>::iterator it=q.begin(),l=q.end();
            if(q.size()<=n-i)q.insert(q.begin(), q.begin(), q.end());
        }
    }
    return 0;
}
