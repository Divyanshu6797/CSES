#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Approach:
1. We have n applicants and m apartments, with desired size differences at most k
2. For optimal matching:
   - Sort both applicant desires and apartment sizes
   - Use two pointers to match applicants with apartments
   - If difference between current applicant and apartment <= k, we found a match
   - If applicant desires smaller apartment, move to next applicant
   - If apartment is too small, move to next apartment
3. Time Complexity: O(nlogn + mlogm) for sorting
4. Space Complexity: O(1) extra space (excluding input storage)
*/

int main() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> applicants(n);
    vector<int> apartments(m);

    for(int i = 0 ;i < n;i++) {
        cin>>applicants[i];
    }
    for(int i = 0;i <m;i++) {
        cin>>apartments[i];
    }

    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int a = 0;
    int b = 0;
    int ans = 0;

    while(a < n && b < m) {
        if(abs(applicants[a] - apartments[b]) <= k) {
            ans++;
            a++;
            b++;
        } else if(applicants[a] < apartments[b]) {
            a++;
        } else {
            b++;
        }
        
    }
    cout << ans << endl;
}
