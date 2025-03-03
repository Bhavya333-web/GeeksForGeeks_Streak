//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
     vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size();
        int maxLen = 0, startIdx = 0;
        multiset<int> window;
        for(int r = 0, l = 0; r < n; r++) {
            window.insert(arr[r]);
            
            while(*window.rbegin() - *window.begin() > x) {
                window.erase(window.find(arr[l]));
                l++;
            }
            
            if(r - l + 1 > maxLen) {
                maxLen = r - l + 1;
                startIdx = l;
            }
        }
        // return longest subarray
        return vector<int>(arr.begin() + startIdx, arr.begin() + startIdx + maxLen);
        
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends