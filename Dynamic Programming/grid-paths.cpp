#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7; 

int main() {
    int n;
    cin >> n;
    vector<vector<char> > a(n, vector<char>(n)); 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<long long int> > dp(n, vector<long long int>(n, 0)); 
    for (int i = 0; i < n; i++) {
        if (a[0][i] == '.') dp[0][i] = 1;
        else break;       // important : should stop when we find *
    }
    for (int i = 0; i < n; i++) {
        if (a[i][0] == '.') dp[i][0] = 1;
        else break;      // important : should stop when we find *
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (a[i][j] == '.') {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }
    }
    cout << dp[n - 1][n - 1] << endl;
    return 0;
}
