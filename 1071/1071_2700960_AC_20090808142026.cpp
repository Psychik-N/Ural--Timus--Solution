#include<iostream>
using namespace std;
//ifstream cin("1071.in");
//ofstream cout("1071.out");
int fy[4000000];

int main(){
    int x,y,i,tx,ty,flen,tl;   
    cin>>x>>y;
    for(i=2;i<=x;i++){
        flen=0;
        ty=y;
        tx=x;
        tl=0;
        while(ty!=0){
            fy[flen]=ty%i;
            flen++;
            ty/=i;
        }
        while(tx!=0){
            if(tx%i==fy[tl]){
                tl++;
                if(tl==flen){
                    cout<<i;
                    system("pause");
                    return 0;
                }
            }
            tx/=i;
        }
    }
    cout<<"No solution";
    system("pause");
}

    
