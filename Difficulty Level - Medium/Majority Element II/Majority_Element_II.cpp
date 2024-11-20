#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
   vector<int> findMajority(vector<int>& arr) {
        vector<int> ans; 
        int n = arr.size(); 
        sort(arr.begin(),arr.end()); 
        int count =1; 
        int num; 
        for(int i =0;i<n-1;i++){
            num = arr[i];
            if(arr[i]==arr[i+1]){
                count++; 
            }
            else{
                if(count > n/3 ){
                    ans.push_back(num); 
                }
                count = 1; 
            }
        }
        if (count > n / 3) {
            ans.push_back(arr[n-1]);
        }
        return ans ; 
    }

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends