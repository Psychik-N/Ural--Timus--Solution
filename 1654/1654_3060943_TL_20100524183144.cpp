#include<iostream>
#include<string.h>
using namespace std;
char ss[200001],data[200001];
int main(){
    int nd,i,ndd;
    cin>>ss;
    ndd=0;
    for (i=1;i<=strlen(ss);i++){
        if((ndd>0)&&(data[ndd-1]==ss[i-1]))ndd--;
        else {ndd++;data[ndd-1]=ss[i-1];}
        
    }
    for (i=1;i<=ndd;i++) cout<<(data[i-1]);
    system("pause");
    return 0;
}
