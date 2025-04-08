#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// Comparator to sort pairs based on the first element
bool comparator(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);

    // Read input and store each number with its original index
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i; // Storing original position
    }

    // Sort the array based on the value (first element of pair)
    sort(a.begin(), a.end(), comparator);

    int ans = 0;
    // Count how many times the original index goes backwards
    // This helps in identifying the number of segments where a new increasing subsequence starts
    for(int i = 1; i < n; i++) {
        if(a[i].second < a[i - 1].second) {
            ans++;
        }
    }

    // The minimum number of such sorted subsequences needed = ans + 1
    cout << (ans + 1);
}
