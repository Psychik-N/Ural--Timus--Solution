#include <stdio.h>
#include <time.h>
int main(){
    int i;
    srand((unsigned)time(0));
    for(i=0;i<1000000;i++)putchar(rand()%26+'a');
}
