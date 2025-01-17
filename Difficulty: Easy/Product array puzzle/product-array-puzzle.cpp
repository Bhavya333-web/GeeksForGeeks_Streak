//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        
    int n = arr.size(), mul = 1, count = 0;
    vector<int> ans(n, 0);

    for (int i : arr) {
        if (i != 0) mul *= i;
        else count++;
    }

    if (count > 1) return ans;
    else if (count==1){
        for (int i=0;i<n;i++){
            if (arr[i]==0){
                ans[i]=mul;
                break;
            }
        }
    }
    else{
        for (int i=0;i<n;i++){
            ans[i]=mul/arr[i];
        }
    }
    return ans;
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

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends