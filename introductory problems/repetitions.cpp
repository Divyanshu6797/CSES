#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    long long n = str.size();
    // if(n==1) return 1;
    char temp = str[0];
    int count = 1;
    int ans = INT_MIN;
    for(int i =1; i < n ;i++) {
        if(str[i] == temp) {
            count++;
        } else {
            temp = str[i];
            count = 1;

        }
        ans = max(ans, count);
    }
    if( n==1 || ans == INT_MIN) cout<< 1;
    else cout << ans;


}
