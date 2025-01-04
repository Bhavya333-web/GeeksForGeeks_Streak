//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &a, int target) {
      int ans=0;
      unordered_map<int,int>m;
      for(auto &i:a)m[i]++;
      for(int i=0;i<a.size();i++){
          m[a[i]]--;
          for(int j=i-1;j>=0;j--){
              
              if(m.find(target-(a[i]+a[j]))!=m.end())
                ans+=m[target-(a[i]+a[j])];
          }
      }
      return ans;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends