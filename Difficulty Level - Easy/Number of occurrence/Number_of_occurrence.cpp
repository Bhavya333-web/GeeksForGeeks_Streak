#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    int countFreq(vector<int>& arr, int target) {
        int lo = lastOccurrence(arr, target);
        int fo = firstOccurrence(arr, target);
        if (lo == -1 && fo == -1) return 0;
        return (lo - fo) + 1;
    }

private:
    
    int firstOccurrence(vector<int>& arr, int target) {
        int start = 0, end = arr.size() - 1, fo = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == target) {
                fo = mid;
                end = mid - 1;
            } else if (arr[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return fo;
    }
    int lastOccurrence(vector<int>& arr, int target) {
        int start = 0, end = arr.size() - 1, lo = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == target) {
                lo = mid;
                start = mid + 1;
            } else if (arr[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return lo;
    }
};

// Driver code
int main() {
    int tc;
    cin >> tc; // Number of test cases
    while (tc-- > 0) {
        // Reading array input
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        // Reading target
        int k;
        cin >> k;

        // Solution class instance
        Solution sln;
        int ans = sln.countFreq(arr, k);

        // Output result
        cout << ans << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends
