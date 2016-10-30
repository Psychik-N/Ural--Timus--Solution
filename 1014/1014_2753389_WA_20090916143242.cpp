#include<iostream>
using namespace std;

int main(){
    int n,f[100],fn=0,i,j;;
    cin>>n;
    if(n==0){
        cout<<0;
        return 0;
    }
    while(n>1){
        for(i=9;i>=2;i--){
            if(n%i==0){
                f[fn]=i;
                fn++;
                n/=i;
                goto next;
            }
        }
        cout<<-1;
        return 0;
        next:;
    }
    for(i=0;i<fn;i++){
        for(j=0;j<fn;j++){
            if(f[i]<f[j])swap(f[i],f[j]);
        }
    }
    for(i=0;i<fn;i++)cout<<f[i];
    system("pause");
}