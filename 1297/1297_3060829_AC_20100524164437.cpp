#include<iostream>
using namespace std;
char c[1500]={0};
int main(){
    int i,j,l,max=0,s,e;
    cin>>c;
    l=strlen(c);
    for(i=0;i<strlen(c);i++){
        for(j=1;j<=1000;j++){
            if(i-j+1<0||i+j-1>=l||c[i-j+1]!=c[i+j-1])break;
            if(j*2-1>max){
                max=j*2-1;
                s=i-j+1;
                e=i+j-1;
            }
        }
        for(j=1;j<=1000;j++){
            if(i-j+1<0||i+j>=l||c[i-j+1]!=c[i+j])break;
            if(j*2>max){
                max=j*2;
                s=i-j+1;
                e=i+j;
            }
        }
    }
    for(i=s;i<=e;i++)cout<<c[i];
    system("pause");
}
