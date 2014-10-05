//#include<iostream>
#include <iomanip.h>
#include<math.h>
//using namespace std;

int a[101];
void swap(int i,int j){
     int c;
     c=a[j];
     a[j]=a[i];
     a[i]=c;
}

int main(){
    int n,i,j;
    double ans;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    ans=a[1];
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(a[i]>a[j])swap(i,j);
        }
    }
    ans=a[1];
    for(i=2;i<=n;i++){
        ans=2*sqrt(ans*a[i]);
    }
    cout.setf(ios::fixed); 
    cout<<setprecision(2)<<ans;
    //system("pause");
}
