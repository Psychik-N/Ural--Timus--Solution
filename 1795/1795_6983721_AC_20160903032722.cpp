#include <iostream>
#include <queue>
#include <map>
using namespace std;
struct Person{
    int value;
    string name;
    Person(int value,string name){
        this->value=value;
        this->name=name;
    }
};
int main(){
    int m,n,v,ans=0;
    deque<Person> queue;
    map<string,int> shop;
    Person last(-1,"");
    string str,xx;
    cin>>m;
    while(m-->0){
        cin>>v>>xx>>str;
        shop[str]=v;
    }
    cin>>n;
    while(n-->0){
        cin>>v>>xx>>str;
        queue.push_back(*new Person(v,str));
    }
    while(queue.size()) {
        Person ap=queue.front();
        queue.pop_front();
        if(last.value>0){
            last.value=shop[last.name];
            queue.push_front(last);
            last.value=-1;
        }
        if(ap.value<=shop[ap.name])shop[ap.name]-=ap.value;
        else if(shop[ap.name]==0);
        else last=ap;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
