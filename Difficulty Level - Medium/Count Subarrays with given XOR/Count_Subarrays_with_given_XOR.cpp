//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        map<int, int> mp;
        int sum = 0;
        long long ans = 0;

        for(int i = 0; i < arr.size(); ++i) {
            sum ^= arr[i]; 
            if (sum == k) {
                ++ans; 
            }
            if (mp.find(sum ^ k) != mp.end()) {
                ans += mp[sum ^ k]; 
            }
            mp[sum]++;
        }

        return ans; 
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); 
    while (tc-- > 0) {
        string input;
        getline(cin, input); 

        stringstream ss(input);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num); 
        }

        int k;
        cin >> k;
        cin.ignore(); 
        Solution obj;
        cout << obj.subarrayXor(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends