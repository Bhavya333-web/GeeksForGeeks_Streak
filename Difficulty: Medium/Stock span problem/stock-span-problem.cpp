//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        
        vector<int>ans(n,1);
        stack<int>s;
        
        for(int i=0; i<n; i++)
        {
            while(!s.empty() && arr[s.top()] <= arr[i])
            {
                ans[i] += ans[s.top()];
                s.pop();
            }
            s.push(i);
        }
        return ans;
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
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends