#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> v(n);
    cin >> v[0];
    long long ans = 0;   
    for(long long i=1; i<n; i++) {
        cin >> v[i];
        if(v[i] < v[i-1]) {
            ans += v[i-1] - v[i];
            v[i] = v[i-1];
        }
    }
    cout<< ans;
    
}