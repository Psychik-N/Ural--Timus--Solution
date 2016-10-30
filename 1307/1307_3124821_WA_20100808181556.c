#include <stdio.h>
char in[300000],out[300000];
int main(){
    int i,l=0,p=0,c=0,y=0;
    while((in[l]=getchar())!=EOF)l++;
    in[l]=0;
    for(i=0;i<l;i++)if(in[i]=='^'||in[i]=='~'||in[i]=='\r')while(1);
    for(i=0;i<l;i++){
                     c++;
      if(in[i]=='t'&&in[i+1]=='h'){
        out[p++]='$';
        i++;
      }else if(in[i]=='o'&&in[i+1]=='r'){
        out[p++]='#';
        i++;
      }/*else if(in[i]=='e'&&in[i+1]=='r'){
        out[p++]='$';
        i++;
      }else if(in[i]=='\\'){
        out[p++]='\\';
        out[p++]='\\';
      }else if(in[i]=='.'&&in[i+1]==' '){
        out[p++]='^';
        i++;
      }else if(in[i]==','&&in[i+1]==' '){
        out[p++]='&';
        i++;
      }*/else if(in[i]=='\n'){
        out[p++]='^';
      }else if(in[i]=='\r'){
        out[p++]='~';
      }else out[p++]=in[i];
    }
    out[p]=0;
//    if(p+300>l)while(1);
    puts("/*C*/");
    puts("#include<stdio.h>");
    printf("char s[][1003]={\"");
    for(i=0;i<p;i++){
      putchar(out[i]);
      if(i%1000==999){
        printf("\",\"");
        y++;
      }
    }
        y++;
    printf("\",\"\"};\n");
    puts("int main(){");
    printf("int i,j,l=%d,y=%d;\n",c,y);
    puts("for(i=0;i<y;i++){");
    printf("j=0;\nwhile(s[i][j]!=0){\n");
    puts("if(s[i][j]=='$')printf(\"th\");");
    puts("else if(s[i][j]=='#')printf(\"or\");");
//    puts("else if(s[i]=='$')printf(\"er\");");
//    puts("else if(s[i]=='{')printf(\"\\\"\");");
//    puts("else if(s[i]=='^')printf(\". \");");
//    puts("else if(s[i]=='&')printf(\", \");");
    puts("else if(s[i][j]=='^')printf(\"\\n\");");
    puts("else if(s[i][j]=='~')printf(\"\\r\");");
    puts("else putchar(s[i][j]);");
    printf("j++;\n}\n");
    puts("}");
    puts("}");
}
