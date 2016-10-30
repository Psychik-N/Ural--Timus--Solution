#include<iostream>
using namespace std;
int main(){
    int i,l,k=1;
    char c[20000]={0};
    cin.get(c,20000,EOF);
    l=strlen(c);
    for(i=0;i<l;i++){
        if(c[i]<65||(c[i]>90&&c[i]<97)||c[i]>122){
            cout<<c[i];
            continue;
        }
        if(k==1){
            if(c[i]>=97&&c[i]<=122)c[i]-=32;
            k=0;
            if(c[i]=='.'||c[i]=='!'||c[i]=='?')k=1;
        }else{
            if(c[i]>=65&&c[i]<=90)c[i]+=32;
            k=0;
            if(c[i]=='.'||c[i]=='!'||c[i]=='?')k=1;
        }
        cout<<c[i];
    }
    system("pause");
}