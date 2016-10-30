#include <stdio.h>
int h1[65536],l1=30000,h2[65536],l2=0,m[65536]={0},p2[65536];
void add1(int a){
	int now=l1;
	while(now>0&&a<h1[(now-1)/2]){
		h1[now]=h1[(now-1)/2];
		now=(now-1)/2;
	}
	h1[now]=a;
	l1++;
}
int get1(){
	int now=0,dest,r=h1[0];
	l1--;
	while(l1>now*2+1){
		if(l1==now*2+2)dest=now*2+1;
		else if(h1[now*2+1]<h1[now*2+2])dest=now*2+1;
		else dest=now*2+2;
		if(h1[l1]<=h1[dest])break;
		h1[now]=h1[dest];
		now=dest;
	}
	h2[now]=h2[l1];
	return r;
}
void add2(int a){
	int now=l2;
	while(now>0&&m[a]<m[h2[(now-1)/2]]){
		h2[now]=h2[(now-1)/2];
		p2[h2[now]]=now;
		now=(now-1)/2;
	}
	h2[now]=a;
	p2[a]=now;
	l2++;
}
void adj2(int a){
	int now=p2[a],dest,t;
	while(l2>now*2+1){
		if(l2==now*2+2)dest=now*2+1;
		else if(m[h2[now*2+1]]<m[h2[now*2+2]])dest=now*2+1;
		else dest=now*2+2;
		if(m[h2[now]]<=m[h2[dest]])break;
		t=h2[now];
		h2[now]=h2[dest];
		h2[dest]=t;
		p2[h2[(now-1)/2]]=(now-1)/2;
		p2[h2[now]]=now;
		now=dest;
	}
}
int get2(){
	int r=h2[0];
	l2--;
	if(l2==0)return r;
	h2[0]=h2[l2];
	p2[h2[0]]=0;
	adj2(h2[0]);
	return r;
}
int main(){
	int i,a,b,t;
	char s[5];
	for(i=0;i<30000;i++)h1[i]=i+1;
	while(scanf("%d %s",&a,s)!=EOF){
		while(l2>0&&m[h2[0]]<a){
			t=get2();
			m[t]=0;
			add1(t);
		}
		if(s[0]=='+'){
			t=get1();
			printf("%d\n",t);
			m[t]=a+599;
			add2(t);
		}else{
			scanf("%d",&b);
			if(m[b]==0)printf("-\n");
			else{
				printf("+\n");
				m[b]=a+599;
				adj2(b);
			}
		}
	}
	return 0;
}
