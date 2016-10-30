char s[5],b1[]={1,2,2,1},b2[]={1,2,2,2,2,1},b3[]={1,0,2,2,0,0,2,2,0,0,1},a[3][10]={"neither","window","aisle"};
int x,y;
int main(){
gets(s);
if(s[2]){
x=10*(s[0]-48)+s[1]-48;
y=s[2]-65;
}else{
x=s[0]-48;
y=s[1]-65;
}
if(x<3)puts(a[b1[y]]);
else if(x<21)puts(a[b2[y]]);
else puts(a[b3[y]]);
}