#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> v(n-1);   
    for(long long i=0; i<n-1; i++) {
        cin >> v[i];
    }
    long long original_sum = accumulate(v.begin(), v.end(), 0LL);
    long long expected_sum = (n*(n+1))/2;
    cout << expected_sum - original_sum;                                                                                                                                  

}


// Approach to solve the problem : subtract the sum of the given numbers from the sum of the numbers from 1 to n. The result is the missing number.