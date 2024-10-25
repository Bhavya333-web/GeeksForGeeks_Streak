#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getSingle(vector<int>& arr) {
        int xora = 0, n = arr.size();
        for (int i = 0; i < n; i++) {
            xora = xora ^ arr[i];
        }
        return xora;
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
        int res = obj.getSingle(arr);
        cout << res << endl;
    }
    return 0;
}