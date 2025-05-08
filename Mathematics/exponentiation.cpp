#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long MOD = 1000000007;

long long calcPower(long long a, int x) {
    long long result = 1;
    // Standard modular exponentiation
    while(x > 0) {
        if(x % 2 == 1) {
            result = (result * a) % MOD;
        }
        a = (a * a) % MOD;
        x /= 2;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long a;
        int x;
        cin >> a >> x;
        cout << calcPower(a, x) << endl;
    }
    return 0;
}
