#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minRepeats(string A, string B) {
        string rep = A;
        int cnt=1;
        while(A.size()<B.size()){
            A+=rep;
            cnt++;
        }
        if(A.find(B)!=-1) return cnt;
         A+=rep;
         cnt++;
        if(A.find(B)!=-1) return cnt;
        return -1;
    }
};
int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}