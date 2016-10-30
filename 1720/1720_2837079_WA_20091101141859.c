#include <stdio.h>
long long lmin(long long a,long long b){
	if(a<b)return a;
	return b;
}
long long lmax(long long a,long long b){
	if(a>b)return a;
	return b;
}
long long z(long long a){
	if(a>0)return a;
	return 0;
}
int main(){
	long long x,y,l,r,t=0,f,ls,rs;
	scanf("%I64d%I64d%I64d%I64d",&x,&y,&l,&r);
	y=lmin(y,x*2-1);
	ls=l/x;
	rs=r/x;
	if(l<x)l=x;
	if(r<l){
		puts("0");
		return 0;
	}
	if(x==y){
		t=(r-l)/x;
		if(l%x==0&&r%x==0)t++;
			printf("%I64d",t);
		return 0;
	}
	f=(2*x-y-1)/(y-x);
	if(ls==rs){
		if(r/y<rs)printf("%I64d",z(r)-l+1);
		else printf("%I64d",z(rs*y)-l+1);
		return 0;
	}
	if((2*x-y-1)%(y-x)==0)f++;
	if(ls<f)t+=(1+(y-x)*ls+1+(y-x)*lmin(f-1,rs))*(lmin(f,rs+1)-ls)/2;
	if(rs>=f)t+=x*(rs-f+1);
	if(ls<f&&l/y<ls)t-=z(ls*y-l+1);
	else if(ls<f)t-=ls*(y-x)+1;
	else t-=l-ls*x+1;
	if((rs+1)*x-1/y<rs)t-=z((rs+1)*x-1-r);
	else t-=z(rs*y-r);
	printf("%I64d",t);
	return 0;
}
