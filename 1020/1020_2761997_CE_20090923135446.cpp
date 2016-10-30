#include<iomanip.h>
#include<cmath>
#include<stdio.h>

int main(){
    float r,s[101][2],pi=3.1415,ans=0;
    int i,n;
    cin>>n>>r;
    for(i=0;i<n;i++){
        cin>>s[i][0]>>s[i][1];
    }
    for(i=0;i<n;i++){
        ans+=sqrt((s[i][0]-s[(i+1)%n][0])*(s[i][0]-s[(i+1)%n][0])+(s[i][1]-s[(i+1)%n][1])*(s[i][1]-s[(i+1)%n][1]));
    }
    ans+=pi*r*2;
    cout<<setiosflags(ios::fixed);   
    cout<<setprecision(2)<<ans;
    system("pause");
}