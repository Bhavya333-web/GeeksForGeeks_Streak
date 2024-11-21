#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int answer=0;
        int sellindex=0;
        int buyindex=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<prices[i-1]){
                sellindex=i-1;
                answer=answer+prices[sellindex]-prices[buyindex];
                buyindex=i;
            }
            if(i==prices.size()-1){
                sellindex=i;
                answer=answer+prices[sellindex]-prices[buyindex];
            }
        }
            return answer;
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
        int n = arr.size();
        Solution ob;
        int res = ob.maximumProfit(arr);
        cout << res;
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends