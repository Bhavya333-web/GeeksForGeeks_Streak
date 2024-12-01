#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    char nonRepeatingChar(string &s) {
            int has = 0, rep = 0;
            for(const char & ch : s) {
                int h = 1 << (ch - 'a');
                if((has & h) == h) {
                    rep |= h;
                }
                else{
                    has |= h;
                }
            }
            for(const char & ch : s) {
                int h = 1 << (ch - 'a');
                if((rep & h) != h) {
                    return ch;
                }
            }
            return '$';
        }
};
int main() {
    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;
        Solution obj;
        char ans = obj.nonRepeatingChar(S);

        if (ans != '$')
            cout << ans;
        else
            cout << "-1";

        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends