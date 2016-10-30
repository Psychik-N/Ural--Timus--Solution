int(c==n)return;
if((now+w[c])*2>=s){
int t=(now+w[c])-(s-now-w[c]);
if(t<b)b=t;
}else{
f(c+1,now+w[c]);
}
f(c+1,now);
}
int main(){
cin>>n;
for(i=0;i<n;i++){
cin>>w[i];
s+=w[i];
}
b=s;
f(0,0);
cout<<b;
}
