#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Solution Approach:
    // 1. Read n (number of children) and x (max allowed weight per gondola).
    // 2. Store the weights of all children in a vector.
    // 3. Sort the weights in ascending order.
    // 4. Use two pointers (left and right) to try and pair the lightest and heaviest child.
    // 5. If the sum of the weights at left and right is <= x, pair them (increment left).
    // 6. In either case, allocate a gondola (decrement right) and increment gondola count.
    // 7. The time complexity is O(n log n) due to sorting.
    
    int n, x;
    cin >> n >> x;
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    sort(weights.begin(), weights.end());
    
    int left = 0, right = n - 1;
    int gondolas = 0;
    while (left <= right) {
        if (left == right) { // Only one child left
            gondolas++;
            break;
        }
        if (weights[left] + weights[right] <= x) {
            left++;  // Pair the lightest with the heaviest child
        }
        right--;  // Allocate gondola for the heaviest child (paired or alone)
        gondolas++;
    }
    
    cout << gondolas << endl; // Time Complexity: O(n log n)
    return 0;
}
