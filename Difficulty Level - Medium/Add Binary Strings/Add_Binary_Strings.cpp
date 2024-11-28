#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string A, string B)
{
    // your code here
    int carry = 0;
    int i = A.length() - 1;
    int j = B.length() - 1;
    string result = "";
 
    while (i >= 0 || j >= 0 || carry == 1) {
        int sum = carry;
 
        if (i >= 0) {
            sum += A[i--] - '0';
        }
        
        if (j >= 0) {
            sum += B[j--] - '0';
        }
 
        result += to_string(sum % 2);
        carry = sum / 2;
    }
 
    reverse(result.begin(), result.end());
 
    // Remove trailing zeros
    int idx = 0;
    while (idx < result.size() - 1 && result[idx] == '0') {
        idx++;
    }
    result = result.substr(idx);
 
    return result;
 
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends