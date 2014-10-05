#include <stdio.h>
#include <stdlib.h>
struct Edge{
	int to;
	struct Edge *next;
}*edg[1010]={0},*t;
int ms(){
    int s=0;
    char c,m=0;
    do{
      c=getchar();
    }while((c!='-')&&(c<48||c>57));
    if(c=='-')m=1;
    else s=c-48;
    while(1){
      c=getchar();
      if(c<48||c>57)break;
      s=s*10+c-48;
    }
    if(m)return -s;
    return s;
}
int main(){
	int n,m,i,a,b,c[1010]={0};
	n=ms();m=ms();
	for(i=0;i<m;i++){
		a=ms();b=ms();
		t=malloc(8);
		t->to=b;
		t->next=edg[a];
		edg[a]=t;
		c[b]++;
	}
	for(i=1;i<=n;i++){
		a=ms();
		if(c[a]!=0){
			puts("NO");
			return 0;
		}
		t=edg[a];
		while(t!=0){
			c[t->to]--;
			t=t->next;
		}
	}
	puts("YES");
	return 0;
}

