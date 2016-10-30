#include<iostream>
using namespace std;
char c[4][4];
int check(){
    if(c[1][1]==c[1][2]&&c[1][1]==c[1][3]&&c[1][1]=='X'){return 1;}
    if(c[2][1]==c[2][2]&&c[2][1]==c[2][3]&&c[2][1]=='X'){return 1;}
    if(c[3][1]==c[3][2]&&c[3][1]==c[3][3]&&c[3][1]=='X'){return 1;}
    if(c[1][1]==c[2][1]&&c[1][1]==c[3][1]&&c[1][1]=='X'){return 1;}
    if(c[1][2]==c[2][2]&&c[1][2]==c[3][2]&&c[1][2]=='X'){return 1;}
    if(c[1][3]==c[2][3]&&c[1][3]==c[3][3]&&c[1][3]=='X'){return 1;}
    if(c[1][1]==c[2][2]&&c[1][1]==c[3][3]&&c[1][1]=='X'){return 1;}
    if(c[1][3]==c[2][2]&&c[1][3]==c[3][1]&&c[1][3]=='X'){return 1;}
    if(c[1][1]==c[1][2]&&c[1][1]==c[1][3]&&c[1][1]=='O'){return -1;}
    if(c[2][1]==c[2][2]&&c[2][1]==c[2][3]&&c[2][1]=='O'){return -1;}
    if(c[3][1]==c[3][2]&&c[3][1]==c[3][3]&&c[3][1]=='O'){return -1;}
    if(c[1][1]==c[2][1]&&c[1][1]==c[3][1]&&c[1][1]=='O'){return -1;}
    if(c[1][2]==c[2][2]&&c[1][2]==c[3][2]&&c[1][2]=='O'){return -1;}
    if(c[1][3]==c[2][3]&&c[1][3]==c[3][3]&&c[1][3]=='O'){return -1;}
    if(c[1][1]==c[2][2]&&c[1][1]==c[3][3]&&c[1][1]=='O'){return -1;}
    if(c[1][3]==c[2][2]&&c[1][3]==c[3][1]&&c[1][3]=='O'){return -1;}
    return 0;
}
int main(){
    cin>>c[1][1]>>c[1][2]>>c[1][3]>>c[2][1]>>c[2][2]>>c[2][3]>>c[3][1]>>c[3][2]>>c[3][3];
    if(check()==1){
        cout<<"win=";return 0;
    }
    if(check()==-1){
        cout<<"Ouths win";return 0;
    }
    int i,j,y=0;
    for(i=1;i<=3;i++)for(j=1;j<=3;j++){
        if(c[i][i]!='#')continue;
        c[i][j]='X';
        if(check()==1){
            cout<<"Crosses win";
            return 0;
        }
        c[i][j]='#';
    }
    for(i=1;i<=3;i++)for(j=1;j<=3;j++){
        if(c[i][i]!='#')continue;
        c[i][j]='O';
        if(check()==-1)y++;
        if(y==2){
            cout<<"Ouths win";
            return 0;
        }
        c[i][j]='#';
    }
    cout<<"Draw";
        
}