#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        if(s1.size()!=s2.size()) return false;
        s1=s1+s1;
        return s1.find(s2)!=string::npos;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution sol;
        int result = sol.areRotations(s1, s2);
        if (result) {
            cout << "true" << endl;

        } else {
            cout << "false" << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}