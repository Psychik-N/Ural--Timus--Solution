﻿#include<iostream>
using namespace std;
char* code;
int n;
int sum=0,t;
int calcsum()
{
    sum=0;
    for(int i=0;i<n;i++)
        {
            if(code[i]=='1')
                sum+= i+1;
        }
    return sum;
}
int main()
{
    
    
    cin>>n;
    code=new char[2000];
    memset(code,0,1500);
    int i=0,j;
    int sum=0;
    while (cin>>code)
    {
        
        
        if(code[n-1]==0)
            goto step2;
        if(code[n]!=0)
            goto step3;
        sum=calcsum();
        if(sum%(n+1)==0)
        {
            for(i=0;i<n;i++)
            {
                cout<<code[i];
            }
            cout<<endl;
            continue;
        }
        ///Step 1
        for(i=0;i<n;i++)
        {
            if(code[i]=='1')
            {
                code[i]='0';
                sum-= i+1;
                if(sum%(n+1)==0)
                {
                    cout<<code;
                    break;
                }
                code[i]='1';
                sum+=i+1;
            }
            
        }
        cout<<endl;
        continue;
        
step2: for(i=n-1;i>=0;i--)
       {
           sum=0;
           for(j=i;j<n;j++)sum+=int(code[j]-48)*(j+2);
           for(j=0;j<i;j++)sum+=int(code[j]-48)*(j+1);
           if(sum%(n+1)==0){
               for(j=0;j<i;j++)cout<<code[j];
               cout<<"0";
               for(j=i;j<n;j++)cout<<code[j];
               break;
           }else if((sum+i+1)%(n+1)==0){
               for(j=0;j<i;j++)cout<<code[j];
               cout<<"1";
               for(j=i;j<n;j++)cout<<code[j];
               break;
           }
       }
        cout<<endl;
        continue;
        
step3: for(i=0;i<=n;i++)
       {
           char temp=code[i];
           for(int j=i;j<=n-1;j++)
               code[j]=code[j+1];
           sum=calcsum();
           if(sum%(n+1)==0)
           {
               for(int k=0;k<=n-1;k++)cout<<code[k];
               break;
           }
           else
           {
               for(int j=n-1;j>=i;j--)
                   code[j+1]=code[j];
               code[i]=temp;
           }
       }
       cout<<endl;
       continue;
       
     }
     
}
