#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
      int missingNumber(vector<int> &arr) {
         sort(arr.begin(),arr.end());
        int num=1;
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i]==num)
            {
                num+=1;
            }
        }
        return num;
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
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }
    return 0;
}
// } Driver Code Ends