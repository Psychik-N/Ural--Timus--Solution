#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

int main(){
    int n,p=0,i,j,flag;
    char c[1001][31];
    cin>>n;gets(c[0]);
    for(i=1;i<=n;i++){
        gets(c[p]);
        flag=true;
        for(j=0;j<p;j++){
            
            if(strcmp(c[p],c[j])==0){
                flag=false;
            }
            
        }
        if(flag)p++;
    }
    cout<<n-p;
    system("pause");
}
