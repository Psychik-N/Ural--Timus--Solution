#include <stdio.h>
#include <stdlib.h>
struct Edge{
	int to;
	struct Edge *next;
}*edg[1010]={0},*t;
int main(){
	int n,m,i,a,b,c[1010]={0};
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		t=malloc(8);
		t->to=b;
		t->next=edg[a];
		edg[a]=t;
		c[b]++;
	}
	for(i=1;i<=n;i++){
		scanf("%d",&a);
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
