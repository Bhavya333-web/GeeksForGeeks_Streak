//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        if(arr.size() == 1)
        {
            return {};
        }
        
        sort(arr.begin(),arr.end());
        int i=0;
        int j=arr.size()-1;
        int ans1 = 0;
        int ans2 = 0;
        int diff;
        int maxi = INT_MAX;
        
        while(i < j)
        {
            int sum = arr[i]+arr[j];
            if(sum == target)
            {
                return {arr[i],arr[j]};
            }
            else
            {
                int rem = abs(target-sum);
                if(maxi > rem)
                {
                    ans1 = arr[i];
                    ans2 = arr[j];
                    maxi = rem;
                    diff = arr[j]-arr[i];
                }
                else if(maxi == rem)
                {
                    int di = arr[j]-arr[i];
                    if(diff < di)
                    {
                        ans1 = arr[i];
                        ans2 = arr[j];
                        diff = di;
                    }
                }
            }
            
            if(sum < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return {ans1, ans2};
    }
};

//{ Driver Code Starts.
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
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends