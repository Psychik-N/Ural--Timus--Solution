#include<iostream>
using namespace std;
int A[11000], ans[11000];
int N, L1, i;
int i2, l, cnt, tmp;

int BinarySearch(int x){
    int p, q, i, L;
    p = 0; 
    q = N-1;
    L = 0; 
    while (p <= q){
        i = (p + q) / 2;
        ++L;
        if (A[i] == x){
            return L;
        }
        if (x < A[i])
        q = i - 1;
        else p = i + 1;
    }
    return 0;
}


int main(){
    cin>>i>>L1;
    for (i2 = 0; i2 <= 10000; i2++){
        A[i2] = i2;
        N = i2;
        if (BinarySearch(i) == L1){
            ans[i2] = 1;
        }
    }
    cnt = 0;
    tmp = 0;
    for (i2 = 0; i2 <= 10000; i2++){
        if (ans[i2] == 0) tmp = 0;
        else {
             if (tmp == 0) cnt++;
             tmp = 1;
        }
    }
    cout<<cnt<<endl; 
    tmp = 0;
    l = -1; 
    for (i2 = 0; i2 <= 10000; i2++){
        if (ans[i2] == 0){
           if (l != -1)cout<<l<<i2-1<<endl; 
           l = -1;
           tmp = 0;
        }else {
              if (tmp == 0) l = i2;
              tmp = 1;
        }
    }
    if (l != -1) cout<<l<<N;
} 