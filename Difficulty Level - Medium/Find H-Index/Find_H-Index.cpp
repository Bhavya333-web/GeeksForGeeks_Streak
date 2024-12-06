#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        // code here
       // Time Complexity: O(n)  | Space Complexity: O(n)
        int n = citations.size();
        vector<int> citarr(n+1,0);
        for(int i:citations){
            citarr[ min(i,n) ]++;
        }
        int citres = 0;
        for(int hidx = n;hidx>=0;hidx--){
            citres += citarr[hidx];
            if(citres >= hidx) return hidx;
        }
        return 0;
    }
};
int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int result = ob.hIndex(arr);

        cout << result << endl;

        cout << "~" << endl;
    }
    return 0;
}