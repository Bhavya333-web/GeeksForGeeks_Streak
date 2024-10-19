//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    string roundToNearest(string str) {
        int n = str.length();
        // Create a string to hold the result
        string ans = str;

        // Check the last character to decide rounding
        if (str[n - 1] <= '5') {
            ans[n - 1] = '0';
        } else {
            ans[n - 1] = '0';
            bool carry = true;
            int i = n - 2;
            while (carry && i >= 0) {
                if (ans[i] == '9') {
                    ans[i] = '0';
                    --i;
                } else {
                    ans[i]++;
                    carry = false;
                }
            }
            // If we still have carry left, we need to add a new digit at the beginning
            if (carry) {
                ans = "1" + string(n, '0');
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends