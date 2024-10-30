#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int countPairsWithDiffK(vector<int>& arr, int k) {
        map <int, int> mp;
        int ans = 0;
        for(auto& e: arr) mp[e]++;
        for(auto& e: arr) ans += (mp[e-k] + mp[e+k]);
        return ans/2;
    }
};
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        auto ans = ob.countPairsWithDiffK(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}