//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int countgroup(vector<int>& arr) { 
        int n = arr.size();
        long long total = 0;
        
        // Calculate XOR of all elements
        for (int i = 0; i < n; i++) {
            total ^= arr[i];
        }

        // If the XOR is not 0, there can be no valid groups
        if (total != 0) {
            return 0;
        } else {
            // Calculate number of valid groups using modular exponentiation
            long long result = 1;  // Start with 1 for 2^0
            for (int i = 0; i < n - 1; i++) {
                result = (result * 2) % 1000000007;  // Calculate 2^(n-1) % 1000000007
            }
            return (result - 1 + 1000000007) % 1000000007;  // Subtract 1 and ensure non-negative
        }
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int ans = obj.countgroup(arr);
        cout << ans << endl;
    }
}

// } Driver Code Ends