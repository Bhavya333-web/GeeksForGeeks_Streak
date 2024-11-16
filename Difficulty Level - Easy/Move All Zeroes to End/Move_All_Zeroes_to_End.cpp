#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int j=0,n=arr.size();
        for(int i=0;i<n;i++)if(arr[i])swap(arr[i],arr[j++]);

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
        int n = arr.size();
        ob.pushZerosToEnd(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends