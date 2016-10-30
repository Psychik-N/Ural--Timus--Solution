#include <stdio.h>
typedef long long i64;
i64 go(i64 v){
i64 ret=0;
int t=2;
while(v>0&&v>=t){
ret+=v/t;
v-=v/t;
t++;
}
return ret;
}
int main(){
i64 l,r;
scanf("%lld%lld",&l,&r);
printf("%lld\n",go(r)-go(l-1));
return 0;
}
