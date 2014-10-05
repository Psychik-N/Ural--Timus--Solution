int main(){
int n,a=0,b=0,c=0,i;
char x[30],y[30],z[30],in[30];
gets(in);
while(gets(in)){
if(in[0]=='E'){
if(a==0){
i=0;
while(in[i]){
x[i]=in[i];
i++;
}
x[i]=0;
}
a++;
}
if(in[0]=='M'){
if(b==0){
i=0;
while(in[i]){
y[i]=in[i];
i++;
}
y[i]=0;
}
b++;
}
if(in[0]=='L'){
if(c==0){
i=0;
while(in[i]){
z[i]=in[i];
i++;
}
z[i]=0;
}
c++;
}
}
if(a>b&&a>c)puts(x);
else if(b>a&&b>c)puts(y);
else puts(z);
}
