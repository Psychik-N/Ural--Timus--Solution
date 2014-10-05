#include <stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    a++;
    if(a/100000+(a/10000)%10+(a/1000)%10==(a/100)%10+(a/10)%10+a%10){puts("Yes");return 0;}
    a--;
    a--;
    if(a/100000+(a/10000)%10+(a/1000)%10==(a/100)%10+(a/10)%10+a%10){puts("Yes");return 0;}
    puts("No");
}
