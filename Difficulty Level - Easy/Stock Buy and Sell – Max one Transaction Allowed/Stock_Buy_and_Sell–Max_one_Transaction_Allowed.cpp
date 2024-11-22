#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int maxProfit = 0; 
        int mbp = prices[0]; 
        for(int i =1;i<prices.size();i++){
            mbp = min(mbp , prices[i]); // Track the minimum buying Prices
            maxProfit = max(maxProfit,prices[i] - mbp); // to calculate maximum Profit
        }
        return maxProfit;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends