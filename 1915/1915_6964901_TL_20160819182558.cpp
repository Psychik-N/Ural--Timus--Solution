#include <iostream>
using namespace std;
const int SIZE=1000002;
class deque{
public:
    int a[SIZE];
    int head=0,tail=0,size=0;
    void push_front(int v){
        a[head]=v;
        head++;
        if(head==SIZE)head=0;
        if(size==0){
            tail--;
            if(tail<0)tail=SIZE-1;
        }
        size++;
    }
    void push_back(int v){
        a[tail]=v;
        tail--;
        if(tail==-1)tail=SIZE-1;
        if(size==0){
            head++;
            if(head==SIZE)head=0;
        }
        size++;
    }
    int front(){
        return *begin();
    }
    void pop_back(){
        tail++;
        if(tail==SIZE)tail=0;
        size--;
        if(size==0)head=tail=0;
    }
    void pop_front(){
        head--;
        if(head==-1)head=SIZE-1;
        size--;
        if(size==0)head=tail=0;
    }
    int *begin(){
        int th=head-1;
        if(th==-1)th=SIZE-1;
        return &a[th];
    }
    int *end(){
        return &a[tail];
    }
    int *nxt(int *p){
        p--;
        if(p<a)p=a+SIZE-1;
        return p;
    }
};
int main(){
    deque q;
    int n,t,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&t);
        if(t>0){
            q.push_front(t);
            while(q.size>n-i)q.pop_back();
        }else if(t<0){
            printf("%d\n",q.front());
            q.pop_front();
        }else{
            if(q.size==0)continue;
            int *it=q.begin(),*l=q.end();
            while(it!=l&&q.size<=n-i){
                q.push_back(*it);
                it=q.nxt(it);
            }
        }
    }
    return 0;
}
