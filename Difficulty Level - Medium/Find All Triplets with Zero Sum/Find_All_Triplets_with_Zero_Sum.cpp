//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
   vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        unordered_map<int,vector<pair<int,int>>> mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mp[arr[i]+arr[j]].push_back({i,j});
            }
        }
        vector<vector<int>> ans;
        for(int i=2;i<n;i++){
            int rem=-arr[i];
            if(mp.find(rem)!=mp.end()){
                for(auto j: mp[rem]){
                    if(j.second<i){
                        ans.push_back({j.first,j.second,i});
                    }
                }
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
        Solution ob;

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends