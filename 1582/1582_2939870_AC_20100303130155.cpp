#include <iostream>
#include <math.h>
using namespace std;
int main() {
    double k1, k2, k3;
    cin>>k1>>k2>>k3;
    cout<<int(0.5+1000/(k2/k3+k2/k1+1)*k2);
    return 0;
} 