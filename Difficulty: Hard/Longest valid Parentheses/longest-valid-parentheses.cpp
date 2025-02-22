//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxLength(string& s) {
        // code here
        int maxlen = 0; // annswer
        vector<int>dp(s.size() , 0); 
        /*
            for some index (i) :=
            dp[i] = 1 , a balanced parenthesis succeeds or preceeds with (i)
        */
        
        stack<int>open;
        for(size_t i = 0 ; i < s.size() ; i++) {
            // if (i)th element is open parenthesis
            if(s[i] == '(') {
                open.push(i); // push (i) stack
            } else {
            // if (i)th element is close parenthesis
            
            // requires matching open paranthesis to balance
                if(!open.empty()) {
                    // increment by 1 at both open and close
                    // parenthesis indexes
                    dp[i] += 1; 
                    dp[open.top()] += 1;
                    open.pop(); // pop from stack 
                }
            }
        }
        
        // iterate through 'dp'
        for(int j = 1 ; j < dp.size() ; j++) {
            if(dp[j] == 0) continue; // if no balanced string starts at (j)
            dp[j] += dp[j - 1]; // prefix sum
            maxlen = std :: max(maxlen , dp[j]); // get max length of subsequent balanced string
        }
        return maxlen;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends