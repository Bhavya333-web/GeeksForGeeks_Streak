//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Your code here
        int res = 0;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); ++i) {
            int val = target - arr[i];
            
            // Find the first element that is NOT less than `val`.
            auto itr = lower_bound(arr.begin() + i + 1, arr.end(), val);
            
            // Count all elements before `itr`.
            res += itr - (arr.begin() + i + 1);
        }
        
        return res;
    }
 
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);
        cout << res << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends