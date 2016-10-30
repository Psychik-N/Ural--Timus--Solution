#include<iostream>
using namespace std;

int main(){
    int p=0,r=0,len;
    char c[80],tc[10000],ttc[0];
    while(gets(ttc)){
        tc[r]=ttc[0];
    }
    r=0;
    len=strlen(tc);
    cout<<len;
    for(p=0;p<80;p++){
        c[p]=32;
    } 
    for(r=0;r<len;r++){
        if(tc[r]=='<'){
            p--;
            if(p<0||p>79)r=0;
        }
        else if(tc[r]=='>'){
            p++;
            if(p<0||p>79)r=0;
        }
        else{
            c[p]=tc[r];
        }
    }
    for(p=0;p<80;p++){
        cout<<c[p];
    } 
    system("pause");
}
