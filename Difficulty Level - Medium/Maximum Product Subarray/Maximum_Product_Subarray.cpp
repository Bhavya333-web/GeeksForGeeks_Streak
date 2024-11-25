#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxProduct(vector<int>& a) {
    int n = a.size();
    if (n == 0) return 0;

    int maxi = 1;         // Maximum product of subarray ending at the current position
    int mini = 1;         
    int mx = a[0];        
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
           
            swap(maxi, mini);
        }
        maxi = max(a[i], maxi * a[i]);
        mini = min(a[i], mini * a[i]);

        // Update the global maximum
        mx = max(mx, maxi);
    }

    return mx;
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
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends