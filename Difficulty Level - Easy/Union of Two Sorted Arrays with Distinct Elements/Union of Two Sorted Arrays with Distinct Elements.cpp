#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        vector<int>ans;
        int i=0;
        int j=0;
        while(i<a.size() && j<b.size()){
            if(a[i]==b[j])
            ans.push_back(a[i]),i++,j++;
            else if(a[i]>b[j])
            ans.push_back(b[j]),j++;
            else
            ans.push_back(a[i]),i++;
        }
        while(i<a.size()){
            if(i==0)
            ans.push_back(a[i]);
            else if(i!=0 && ans.back()!=a[i])
            ans.push_back(a[i]);
            i++;
        }
        while(j<b.size()){
            if(j==0)
            ans.push_back(b[j]);
            else if(j!=0 && b[j]!=ans.back())
        ans.push_back(b[j]);
        j++;
        }
        return ans;
    }
};
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }
        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}