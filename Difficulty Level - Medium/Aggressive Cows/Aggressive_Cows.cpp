#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool findAns(vector<int> &stalls, int mid, int k) {
        int cnt = 1;           
        int prev = 0;           
        
        for (int i = 1; i < stalls.size(); ++i) {
            
            if (stalls[i] - stalls[prev] >= mid) {
                ++cnt;          
                prev = i;      
            }
        }
        return cnt >= k;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        int low = 0;                     
        int high = stalls[n - 1] - stalls[0];  
        int ans = -1;                    
        while (low <= high) {
            int mid = low + (high - low) / 2;  
            if (findAns(stalls, mid, k)) {
                ans = mid;       
                low = mid + 1;    
            } else {
                high = mid - 1;   
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