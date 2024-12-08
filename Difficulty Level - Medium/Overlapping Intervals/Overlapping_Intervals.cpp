#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
          int n=  arr.size();
          sort(arr.begin(),arr.end());
          vector<vector<int>>ans;
          for(int i=0;i<n;i++){
                 if(ans.empty() || ans.back()[1]<arr[i][0]){
                        ans.push_back(arr[i]);
                 }
                 else{
                       ans.back()[1] = max(ans.back()[1],arr[i][1]);
                 }
          }
          return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends