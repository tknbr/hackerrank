#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void isPrime(int n){
    if ( n < 2){
        cout << "Not prime" << endl;
        return;
    }
    int sqrt = std::sqrt(n);
    for(int i = 2; i <= sqrt; ++i){
        if (n%i == 0){
            cout << "Not prime" << endl;
            return;
        }
    }
    cout << "Prime" << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        int number_to_test; 
        cin >> number_to_test;
        isPrime(number_to_test);
    }
    return 0;
}