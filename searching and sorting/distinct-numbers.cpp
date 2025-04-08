#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	// Replace set with unordered_set for O(1) average case insertions
	unordered_set<int> distinctNumbers;
	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		distinctNumbers.insert(number);
	}

	cout << distinctNumbers.size() << endl;
	return 0;
}

// Time Complexity Analysis:
// 1. Reading n numbers: O(n)
// 2. For each number, insertion into unordered_set: O(1) average case per insertion
// 3. Total complexity: O(n) on average
// 
// Note: In worst case (many hash collisions), time complexity could degrade to O(n²),
// but this is rare with good hash functions
//
// Space Complexity: O(n) in worst case when all numbers are distinct
