﻿#include<iostream>
using namespace std;char s[81]={0};char input[80001]={0};int len,pi,ps;int main(){cin>>input;len=strlen(input);input[len+1]=0;memset(s,0,sizeof(char)*81);pi=0;ps=0;for(pi=0;pi<len;pi++){if(input[pi]=='>')ps++;else if(input[pi]=='<')ps--;else{s[ps]=input[pi];ps++;}if(ps>79 || ps<0)ps=0;}for(int i=0;i<=79;i++)cout<<s[i];system("pause");}