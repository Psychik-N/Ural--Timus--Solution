#include<iostream>
#include<string.h>
using namespace std;
char a[6][6];
int x[11],y[11];
int g(char c)
{
    int flag[111]={0};
    int i;
    for(i=0;i<9;i++){
        if(a[i/3][i%3]==c)
        flag[i]=1;
    }
    if(flag[0]&&flag[1]&&flag[2])
    return 1;
    if(flag[3]&&flag[4]&&flag[5])
    return 1;
    if(flag[6]&&flag[7]&&flag[8])
    return 1;
    if(flag[0]&&flag[3]&&flag[6])
    return 1;
    if(flag[1]&&flag[4]&&flag[7])
    return 1;
    if(flag[2]&&flag[5]&&flag[8])
    return 1;
    if(flag[0]&&flag[4]&&flag[8])
    return 1;
    if(flag[2]&&flag[4]&&flag[6])
    return 1;
    return 0;
}
int f(char c)
{
    int i,j;
    int num=0;
    for(i=0;i<9;i++){
        if(a[i/3][i%3]=='#'){
            a[i/3][i%3]=c;
            if(g(c)){
                num++;
                if(c=='X')
                x[i]=1;
                else
                y[i]=1;
            }
            a[i/3][i%3]='#';
        }
    }
    return num;
}
int main()
{
    int i;
    for(i=0;i<3;i++)
    scanf("%s",a+i);
    int j;
    int num;
    if(f('X')>=1){
        cout<<"Crosses win";
        return 0;
    }
    if(f('O')>1){
        cout<<"Ouths win";
        return 0;
    }
    if(f('O')==1){
        for(i=0;i<9;i++)
        if(y[i]){
            a[i/3][i%3]='X';
        }
        for(i=0;i<9;i++)
        x[i]=y[i]=0;
        if(f('X')>1){
            cout<<"Crosses win";
            return 0;
        }
        cout<<"Draw";
        return 0;
    }
    int max=0;
    for(i=0;i<9;i++){
        if(a[i/3][i%3]=='#'){
            a[i/3][i%3]='X';
            if(f('X')>max)
            max=f('X');
            a[i/3][i%3]='#';
        }
    }
    if(max>1)
    cout<<"Crosses win";
    else
    cout<<"Draw";
}
