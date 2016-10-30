#include <stdio.h>
char in[300000],out[300000];
int main(){
    int i,l=0,p=0;
    while((in[l]=getchar())!=EOF)l++;
    in[l]=0;
    for(i=0;i<l;i++){
      if(in[i]=='t'&&in[i+1]=='h'){
        out[p++]='\140';
        i++;
      }/*else if(in[i]=='i'&&in[i+1]=='n'){
        out[p++]='#';
        i++;
      }else if(in[i]=='e'&&in[i+1]=='r'){
        out[p++]='$';
        i++;
      }*/else if(in[i]=='\\'){
        out[p++]='\141';
      }/*else if(in[i]=='.'&&in[i+1]==' '){
        out[p++]='^';
        i++;
      }else if(in[i]==','&&in[i+1]==' '){
        out[p++]='&';
        i++;
      }*/else if(in[i]=='\n'){
        out[p++]='\142';
      }else if(in[i]=='\r'){
        out[p++]='\143';
      }else out[p++]=in[i];
    }
    puts("/*C*/");
    puts("#include<stdio.h>");
    printf("char s[]={\"%s\"};\n",out);
    puts("int main(){");
    printf("int i=0,l=%d;\n",p);
    puts("for(i=0;i<l;i++){");
    puts("if(s[i]=='\\140')printf(\"th\");");
//    puts("else if(s[i]=='#')printf(\"in\");");
//    puts("else if(s[i]=='$')printf(\"er\");");
    puts("else if(s[i]=='\\141')printf(\"\\\"\");");
//    puts("else if(s[i]=='^')printf(\". \");");
//    puts("else if(s[i]=='&')printf(\", \");");
    puts("else if(s[i]=='\\142')printf(\"\\n\");");
    puts("else if(s[i]=='\\143')printf(\"\\r\");");
    puts("else putchar(s[i]);");
    puts("}");
    puts("}");
}
