//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:

   // Helper function to check if it is possible to place 'k' cows
    // with at least 'mid' distance between them
    bool findAns(vector<int> &stalls, int mid, int k) {
        int cnt = 1;            // Start by placing the first cow
        int prev = 0;           // Keep track of the last placed cow's position
        
        for (int i = 1; i < stalls.size(); ++i) {
            // Place a cow only if the current stall is at least 'mid' away from the last placed cow
            if (stalls[i] - stalls[prev] >= mid) {
                ++cnt;          // Increment cow count
                prev = i;       // Update the last placed cow's position
            }
        }
        
        // If the number of placed cows is >= k, return true
        return cnt >= k;
    }

    // Main function to find the maximum minimum distance
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        
        // Step 1: Sort the stall positions to place cows sequentially
        sort(stalls.begin(), stalls.end());
        
        // Step 2: Initialize binary search range
        int low = 0;                     // Smallest possible distance
        int high = stalls[n - 1] - stalls[0];  // Maximum possible distance
        int ans = -1;                    // Store the best valid distance found
        
        // Step 3: Binary Search on Answer
        while (low <= high) {
            int mid = low + (high - low) / 2;  // Calculate middle distance
            
            // Step 4: Use the helper function to check feasibility
            if (findAns(stalls, mid, k)) {
                ans = mid;        // Update answer as the current mid is valid
                low = mid + 1;    // Search for a larger minimum distance
            } else {
                high = mid - 1;   // Search for a smaller distance
            }
        }
        
        return ans;  // Return the maximum minimum distance found
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends