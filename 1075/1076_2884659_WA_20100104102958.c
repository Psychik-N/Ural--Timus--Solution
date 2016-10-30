#include <stdio.h>
#define oo 2000000000
int c[160][160]={0},from[160],m1[160],m2[160],slack[160],l1[160],l2[160]={0},n;
int dfs(int p){
    int i,t;
    m1[p]=1;
	for(i=0;i<n;i++){
	  if(!m2[i]){
	    t=l1[p]+l2[i]-c[p][i];
	    if(t==0){
	      m2[i]=1;
	      if(from[i]==0||dfs(from[i])){
			from[i]=p;
			return 1;
	      }
        }else if(t<slack[i])slack[i]=t;
	  }
	}
	return 0;
}
void KM(){
     int i,j,delta;
     for(i=0;i<n;i++){
		l1[i]=-oo;
		for(j=0;j<n;j++)
		  if(c[i][j]>l1[i])l1[i]=c[i][j];
	}
	for(i=0;i<n;i++){
      while(1){
		for(j=0;j<n;j++)m1[j]=m2[j]=0;
        for(j=0;j<n;j++)slack[j]=oo;
		if(dfs(i))break;
		delta=oo;
		for(j=0;j<n;j++)
		  if(!m2[j]&&slack[j]<delta)delta=slack[j];
		for(j=0;j<n;j++)
		  if(m1[j])l1[j]-=delta;
		for(j=0;j<n;j++)
		  if(m2[j])l2[j]+=delta;
	  }
	}
}
int main(){
    int i,j,t=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
        scanf("%d",&c[i][j]);
        t+=c[i][j];
      }
    }
    KM();
    for(i=0;i<n;i++)t-=c[from[i]][i];
    printf("%d\n",t);
}
