#include<iostream>
using namespace std;
int main(){
    char c[4][4];
    cin>>c[1][1]>>c[1][2]>>c[1][3]>>c[2][1]>>c[2][2]>>c[2][3]>>c[3][1]>>c[3][2]>>c[3][3];
    if(c[1][1]==c[1][2]&&c[1][1]==c[1][3]&&c[1][1]=='X'){cout<<"Crosses win";return 0;}
    if(c[2][1]==c[2][2]&&c[2][1]==c[2][3]&&c[2][1]=='X'){cout<<"Crosses win";return 0;}
    if(c[3][1]==c[3][2]&&c[3][1]==c[3][3]&&c[3][1]=='X'){cout<<"Crosses win";return 0;}
    if(c[1][1]==c[2][1]&&c[1][1]==c[3][1]&&c[1][1]=='X'){cout<<"Crosses win";return 0;}
    if(c[1][2]==c[2][2]&&c[1][2]==c[3][2]&&c[1][2]=='X'){cout<<"Crosses win";return 0;}
    if(c[1][3]==c[2][3]&&c[1][3]==c[3][3]&&c[1][3]=='X'){cout<<"Crosses win";return 0;}
    if(c[1][1]==c[2][2]&&c[1][1]==c[3][3]&&c[1][1]=='X'){cout<<"Crosses win";return 0;}
    if(c[1][3]==c[2][2]&&c[1][3]==c[3][1]&&c[1][3]=='X'){cout<<"Crosses win";return 0;}
    if(c[1][1]==c[1][2]&&c[1][1]==c[1][3]&&c[1][1]=='O'){cout<<"Ouths win";return 0;}
    if(c[2][1]==c[2][2]&&c[2][1]==c[2][3]&&c[2][1]=='O'){cout<<"Ouths win";return 0;}
    if(c[3][1]==c[3][2]&&c[3][1]==c[3][3]&&c[3][1]=='O'){cout<<"Ouths win";return 0;}
    if(c[1][1]==c[2][1]&&c[1][1]==c[3][1]&&c[1][1]=='O'){cout<<"Ouths win";return 0;}
    if(c[1][2]==c[2][2]&&c[1][2]==c[3][2]&&c[1][2]=='O'){cout<<"Ouths win";return 0;}
    if(c[1][3]==c[2][3]&&c[1][3]==c[3][3]&&c[1][3]=='O'){cout<<"Ouths win";return 0;}
    if(c[1][1]==c[2][2]&&c[1][1]==c[3][3]&&c[1][1]=='O'){cout<<"Ouths win";return 0;}
    if(c[1][3]==c[2][2]&&c[1][3]==c[3][1]&&c[1][3]=='O'){cout<<"Ouths win";return 0;}
    cout<<"Draw";
}