#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        int n=arr.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        vector<vector<int>>ans;
        for(int i=0;i<n-2;i++){
            int first=arr[i],firstInd=i;
            for(int j=i+1;j<n;j++){
                int second=arr[j],secondInd=j;
                int third=-(first+second);
                if(mp.find(third)!=mp.end()){
                    for(auto it:mp[third]){
                        if(it>j) ans.push_back({firstInd,secondInd,it});
                    }
                }
            }
        }
        return ans;
    }
};
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