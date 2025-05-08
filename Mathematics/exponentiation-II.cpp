#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long MOD = 1000000007;

/*
 * Approach for calculating a^(b^c) mod MOD:
 * 
 * 1. We need to calculate b^c first, but this would be a huge number
 *    that won't fit in standard data types.
 * 
 * 2. Using Fermat's Little Theorem and Euler's Theorem:
 *    For any prime p and any integer a not divisible by p:
 *    a^(p-1) ≡ 1 (mod p)
 *    
 *    This means that exponents in modular arithmetic can be reduced modulo (p-1).
 *    So, a^b mod p = a^(b mod (p-1)) mod p, when a and p are coprime.
 *    
 * 3. For our problem, to compute a^(b^c) mod MOD:
 *    - First compute b^c mod (MOD-1) using modular exponentiation
 *    - Then compute a^(result) mod MOD
 *    
 * 4. Note: When a is divisible by MOD, we need special handling, but the problem
 *    constraints make this case simple to address within our implementation.
 * youtube link : https://www.youtube.com/watch?v=YPJ38aWeyGI
 */

long long calcPower(long long a, long long x, long long mod) {
    // Standard modular exponentiation (exponent x should be properly reduced if needed)
    long long result = 1;
    a %= mod;  // Ensure a is within mod range
    while(x > 0) {
        if(x % 2 == 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        x /= 2;
    }
    return result;
}


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        // Corrected: compute b^c mod (MOD - 1) for the exponent
        long long exponent = calcPower(b, c, MOD - 1);
        long long result = calcPower(a, exponent, MOD);
        cout << result << endl;
    }
    return 0;
    
}
