#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool canAttend(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i][0] < arr[i - 1][1]) {
                return false; // Overlap found
            }
        }
        return true; // No overlaps
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> arr[i][0] >> arr[i][1];
        }
        Solution obj;
        bool ans = obj.canAttend(arr);
        cout << (ans ? "true" : "false") << endl;
    }
    return 0;
}
