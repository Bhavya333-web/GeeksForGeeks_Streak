//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int n = arr.size();
        int lo = 0 , hi = n-1;
        int idx = -1;
        
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            int ct = arr[mid] - mid - 1;
            if(ct < k){
                idx = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        int act = arr[idx] - idx - 1;
        return arr[idx] + k - act ;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.kthMissing(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends