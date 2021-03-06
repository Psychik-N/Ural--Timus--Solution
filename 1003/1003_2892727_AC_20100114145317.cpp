﻿#include<iostream>
#include<string>
const int BLOCK=10000,HASHTHING=6000;
int hashTable[20000],father[20000];
int Hash(int number){
    int pos=number %HASHTHING;
    while(hashTable[pos]!=-1 && hashTable[pos]!=number)pos=(pos+1)%HASHTHING;
    hashTable[pos]=number;
    return pos;
}
int Find(int x){
    int root=x;
    while(root!=father[root]) root=father[root];
    while(x!=root)    {
      int temp=father[x];
      father[x]=root;
      x=temp;
    }
    return root;
}
void Union(int x,int y){
     int p=Find(x);
     int q=Find(y);
     if (p!=q)        father[p]=q;
}
int main(){
    while(true)    {
      int len;
      std::cin>>len;
      if(len==-1)break;
      int n;
      std::cin>>n;
      memset(hashTable,0xff,sizeof(hashTable));
      for(int i=0;i<20000;++i) father[i]=i;
      int count;
      for(count=1;count<=n;++count)        {
        int a,b;
        std::string signal;
        std::cin>>a>>b>>signal;
        bool even=(signal=="even");
        a=Hash(a-1);
        b=Hash(b);
        if(even)            {
          if(Find(a)==Find(b+BLOCK))break;
          Union(a,b);
          Union(a+BLOCK,b+BLOCK);
        }else{
          if(Find(a)==Find(b)) break;
          Union(a,b+BLOCK);
          Union(a+BLOCK,b);
        }
      }
      int ans=count-1;
      int tempa,tempb;
      std::string tempstr;
      for(++count;count<=n;++count)            std::cin>>tempa>>tempb>>tempstr;
      std::cout<<ans<<std::endl;
    }
    return 0;
}
