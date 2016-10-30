#include <stdio.h>
char in[300000],out[300000];
int main(){
    int i,l=0,p=0,c=0;
    while((in[l]=getchar())!=EOF)l++;
    in[l]=0;
    for(i=0;i<l;i++){
                     c++;
      if(in[i]=='t'&&in[i+1]=='h'){
        out[p++]='$';
        i++;
      }/*else if(in[i]=='i'&&in[i+1]=='n'){
        out[p++]='#';
        i++;
      }else if(in[i]=='e'&&in[i+1]=='r'){
        out[p++]='$';
        i++;
      }*/else if(in[i]=='\\'){
        out[p++]='\\';
        out[p++]='\\';
      }/*else if(in[i]=='.'&&in[i+1]==' '){
        out[p++]='^';
        i++;
      }else if(in[i]==','&&in[i+1]==' '){
        out[p++]='&';
        i++;
      }*/else if(in[i]=='\n'){
        out[p++]='\\';
        out[p++]='n';
      }else if(in[i]=='\r'){
        out[p++]='\\';
        out[p++]='r';
      }else out[p++]=in[i];
    }
    puts("/*C*/");
    puts("#include<stdio.h>");
    printf("unsigned char s[]={\"%s\"};\n",out);
    puts("int main(){");
    printf("int i=0,l=%d;\n",c);
    puts("for(i=0;i<l;i++){");
    puts("if(s[i]=='$')printf(\"th\");");
//    puts("else if(s[i]=='#')printf(\"in\");");
//    puts("else if(s[i]=='$')printf(\"er\");");
//    puts("else if(s[i]=='{')printf(\"\\\"\");");
//    puts("else if(s[i]=='^')printf(\". \");");
//    puts("else if(s[i]=='&')printf(\", \");");
//    puts("else if(s[i]=='}')printf(\"\\n\");");
//    puts("else if(s[i]=='^')printf(\"\\r\");");
    puts("else putchar(s[i]);");
    puts("}");
    puts("}");
}
