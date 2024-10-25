#include <bits/stdc++.h>
using namespace std;
class Solution {

  public:
    vector<int> alternateSort(vector<int>& arr) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        vector<int> v;
        int j=arr.size()-1;
        
        int k=0;
        
        for(int i=0;i<arr.size();i++){
            
            
            if(i%2==0){
                
                v.push_back(arr[j]);
                j--;
            }
            else{
                v.push_back(arr[k]);
                k++;
            }
        }
        return v;
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
        vector<int> ans = obj.alternateSort(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends