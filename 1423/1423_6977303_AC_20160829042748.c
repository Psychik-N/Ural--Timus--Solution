#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void get_nextval(const char *T, int next[]){
    int j = 0, k = -1;
    next[0] = -1;
    while (T[j] != '\0'){
        if (k == -1 || T[j] == T[k]){
            ++j; ++k;
            if (T[j]!=T[k])next[j] = k;
            else next[j] = next[k];
        }else k = next[k];
    }
}
int KMP(const char *Text,const char* Pattern){
    int len=strlen(Pattern);
    int *next=malloc((len+1)*sizeof(int));
    get_nextval(Pattern,next);
    int index=0,i=0,j=0;
    while(Text[i]!='\0' && Pattern[j]!='\0'){
        if(Text[i]== Pattern[j]){
            ++i;
            ++j;
        }else{
            index += j-next[j];
            if(next[j]!=-1)j=next[j];
            else{
                j=0;
                ++i;
            }
        }
    }
    free(next);
    if(Pattern[j]=='\0')return index;
    else return -1;
}
char a[500010],b[250010];
int main(){
    int n,p;
    scanf("%d%s%s",&n,a,b);
    strncpy(a+n,a,n);
    p=KMP(a,b);
    if(p==-1)puts("-1");
    else printf("%d\n",(n-p)%n);
    return 0;
}
