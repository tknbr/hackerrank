#include <iostream>
using namespace std;

template<typename E> 
void printArray(vector<E> vec){
    for(int i = 0; i < vec.size(); ++i){
        cout << vec[i] << endl;
    }
}

int main(){}