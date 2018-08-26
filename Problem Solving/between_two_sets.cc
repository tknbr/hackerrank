#include <iostream>
#include <vector>
#include <set>

using namespace std;

/**
 * Returns true if all elements of a are factors of b.
 */
bool allFactorsOf(vector<int> &a, int b){
    for(int i = 0; i < a.size(); ++i){
        if(b%a[i] != 0){
            return false;
        }
    }
    return true;
}

/**
 * Returns true if b is a factor of all elements of a
 */
bool factorOfAll(vector<int> &a, int b){
    for(int i = 0; i < a.size(); ++i){
        if(a[i]%b != 0){
            return false;
        }
    }
    return true;
}

/**
 * Return all integers that are factors of the array a in the set [min, max] 
 */
vector<int> findFactorsFirstArray(vector<int> &a, int min, int max){
    vector<int> factors;
    for(int i = min; i < max+1; ++i){
        if(allFactorsOf(a,i)){
            factors.push_back(i);
        }
    }
    return factors;
}

/**
 * Return the number of values in factors that are factor of all elements in a
 */
int findFactorsSecondArray(vector<int> &a, vector<int> &factors){
    int count = 0;
    for(int i = 0; i < factors.size(); ++i){
        if(factorOfAll(a, factors[i])){
            ++count;
        }
    }
    return count;
}

int getTotalX(vector <int> a, vector <int> b) {
    // sort vector a and b
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    int min = a[a.size()-1]; // interval min
    int max = b[0]; //interval max
    vector<int> factors = findFactorsFirstArray(a, min, max);
    return findFactorsSecondArray(b, factors);
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    vector<int> b(m);
    for(int b_i = 0; b_i < m; b_i++){
       cin >> b[b_i];
    }
    int total = getTotalX(a, b);
    cout << total << endl;
    return 0;
}