#include <stdio.h>
char pa[101],pb[101],pc[101],f=1;
void go(){
    if(f==1)pa[0]&=~(char)0x20;
    printf("%s %s %s",pa,pb,pc);
    f=0;
}
int main(){
    char t;
    int cl=0,s=0,jc=0;
    while((t=getchar())!=EOF){
        if(t=='{'){s=1;cl=0;jc=0;}
        else if(t=='('){s=2;cl=0;jc=0;}
        else if(t=='['){s=3;cl=0;jc=0;}
        else if(t=='}'){s=0;pa[cl]=0;}
        else if(t==')'){s=0;pb[cl]=0;}
        else if(t==']'){s=0;pc[cl]=0;}
        else if(s==1)pa[cl++]=t|0x20;
        else if(s==2)pb[cl++]=t|0x20;
        else if(s==3)pc[cl++]=t|0x20;
        else if(t==','){go();putchar(',');jc=1;}
        else if(jc)putchar(t);
    }
    if(pa[0]!=0)go();
    return 0;
}
