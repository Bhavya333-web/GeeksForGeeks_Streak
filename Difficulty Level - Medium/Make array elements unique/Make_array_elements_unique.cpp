#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minIncrements(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int c = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i - 1] >= arr[i]) {
                c += (arr[i - 1] - arr[i] + 1);
                arr[i] = arr[i - 1] + 1;
            }
        }
        return c;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string line;
        cin.ignore();
        getline(cin, line);
        istringstream iss(line);
        vector<int> arr;
        int num;
        while (iss >> num) {
            arr.push_back(num);
        }
        
        Solution obj;
        int result = obj.minIncrements(arr);
        cout << result << endl;
    }
    return 0;
}
