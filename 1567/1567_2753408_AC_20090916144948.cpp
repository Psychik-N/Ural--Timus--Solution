#include<iostream>
using namespace std;

int main(){
    char c[2000];
    int l,i,cost=0;
    gets(c);
    l=strlen(c);
    for(i=0;i<l;i++){
        if(c[i]=='a')cost+=1;
        if(c[i]=='b')cost+=2;
        if(c[i]=='c')cost+=3;
        if(c[i]=='d')cost+=1;
        if(c[i]=='e')cost+=2;
        if(c[i]=='f')cost+=3;
        if(c[i]=='g')cost+=1;
        if(c[i]=='h')cost+=2;
        if(c[i]=='i')cost+=3;
        if(c[i]=='j')cost+=1;
        if(c[i]=='k')cost+=2;
        if(c[i]=='l')cost+=3;
        if(c[i]=='m')cost+=1;
        if(c[i]=='n')cost+=2;
        if(c[i]=='o')cost+=3;
        if(c[i]=='p')cost+=1;
        if(c[i]=='q')cost+=2;
        if(c[i]=='r')cost+=3;
        if(c[i]=='s')cost+=1;
        if(c[i]=='t')cost+=2;
        if(c[i]=='u')cost+=3;
        if(c[i]=='v')cost+=1;
        if(c[i]=='w')cost+=2;
        if(c[i]=='x')cost+=3;
        if(c[i]=='y')cost+=1;
        if(c[i]=='z')cost+=2;
        if(c[i]=='.')cost+=1;
        if(c[i]==',')cost+=2;
        if(c[i]=='!')cost+=3;
        if(c[i]==' ')cost+=1;
    }
    cout<<cost;
    system("pause");
}