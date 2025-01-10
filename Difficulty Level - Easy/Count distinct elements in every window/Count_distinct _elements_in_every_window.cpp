//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        int n=arr.size();
        vector<int>ans;
        queue<int>q;
        unordered_map<int,int>mp;
        for(int i=0;i<k;i++){
            q.push(arr[i]);
            mp[arr[i]]++;
        }
        ans.push_back(mp.size());
        for(int j=k;j<n;j++){
            q.push(arr[j]);
            mp[arr[j]]++;
            int f=q.front();
            q.pop();
            mp[f]--;
            if(mp[f]==0){
                mp.erase(f);
            }
            ans.push_back(mp.size());
        }
        return ans;
    }
};

//{ Driver Code Starts.

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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends