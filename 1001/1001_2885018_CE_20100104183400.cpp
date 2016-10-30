Why this
#include <math.h>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
vector<double> numbers;
double number = 0;
while(cin >> number){
numbers.push_back(number);
}

for(int i = numbers.size() - 1; i >= 0 ; i--){
cout<<setprecision(10)<<sqrt(numbers[i])<<'\n';
}

return 0;
}