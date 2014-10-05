#include <stdio.h>
int pc[66000],pe[66000],ps[66000],s[66000],sl;
int min(int a,int b){
	if(a<b)return a;
	return b;
}
int max(int a,int b){
	if(a>b)return a;
	return b;
}
void init(int p,int s,int e){
	int mid=(s+e)/2;
	ps[p]=s;
	pe[p]=e;
	if(s!=e){
		init(p*2+1,s,mid);
		init(p*2+2,mid+1,e);
	}
}
void add(int p,int s,int e){
	if(ps[p]==s&&pe[p]==e){
		pc[p]++;
		return;
	}
	if(s<=pe[p*2+1])add(p*2+1,s,min(e,pe[p*2+1]));
	if(e>=ps[p*2+2])add(p*2+2,max(s,ps[p*2+2]),e);
}
int query(int p,int n){
	if(ps[p]==pe[p])return pc[p];
	if(n<=pe[p*2+1])return pc[p]+query(p*2+1,n);
	return pc[p]+query(p*2+2,n);
}
void work(){
	int i,bv=-1;
	for(i=0;i<66000;i++)pc[i]=0;
	for(i=0;i<sl;i++)if(s[i]>bv)bv=s[i];
	for(i=0;i<sl;i++)add(0,0,s[i]-1);
	s[0]=sl;
	for(i=1;i<bv;i++)s[i]=query(0,i);
	sl=bv;
}
int main(){
	int i;
	scanf("%d",&sl);
	for(i=0;i<sl;i++)scanf("%d",&s[i]);
	init(0,0,32767);
	work();
	work();
	for(i=0;i<sl;i++)printf("%d\n",s[i]);
	return 0;
}
