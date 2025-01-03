#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countgroup(vector<int>& arr) { 
        int n = arr.size();
        long long total = 0;
        for (int i = 0; i < n; i++) {
            total ^= arr[i];
        }
        if (total != 0) {
            return 0;
        } else {
            long long result = 1; 
            for (int i = 0; i < n - 1; i++) {
                result = (result * 2) % 1000000007;  
            }
            return (result - 1 + 1000000007) % 1000000007; 
        }
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
        Solution obj;
        int ans = obj.countgroup(arr);
        cout << ans << endl;
    }
}