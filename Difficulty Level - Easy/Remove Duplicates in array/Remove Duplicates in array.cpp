#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        // code here
        for(int i=arr.size()-1;i>=0;i--){
            int k=arr[i];
            arr[i]=0;
            auto it=find(arr.begin(),arr.end(),k);
            if(it!=arr.end()){
                arr.erase(arr.begin()+i);
            }
            else arr[i]=k;
        }
        

        return arr;
        
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
        Solution obj;
        vector<int> ans = obj.removeDuplicate(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends