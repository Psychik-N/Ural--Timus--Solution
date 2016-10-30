#include <stdio.h>
#include <string.h>
int main(){
    int n,i,a,b;
    char name[32],date[10],stat[14]={0},p1[3],p2[20],line[100];
    printf("+------------------------------+--------+-------------+\n|Contest name                  |Date    |ABCDEFGHIJKLM|\n+------------------------------+--------+-------------+\n");
    gets(line);
    sscanf(line,"%d",&n);
    while(n-->0){
        gets(name);
        printf("|%s",name);
        for(i=30-(int)strlen(name);i>0;i--)printf(" ");
        gets(date);
        printf("|%s|",date);
        gets(line);
        sscanf(line,"%d%d",&a,&b);
        for(i=0;i<a;i++)stat[i]='.';
        for(i=a;i<13;i++)stat[i]=' ';
        while(b-->0){
            gets(line);
            sscanf(line,"%s%s",p1,p2);
            if(strcmp(p2,"Accepted")==0)stat[p1[0]-'A']='o';
            else if(stat[p1[0]-'A']!='o')stat[p1[0]-'A']='x';
        }
        printf("%s|\n+------------------------------+--------+-------------+\n",stat);
    }
    return 0;
}
