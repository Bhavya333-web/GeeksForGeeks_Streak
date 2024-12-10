//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
        // sort wrt to end time less
    });
        
        int prev=intervals[0][1];
        
       int  ans=0;
       int n=intervals.size();
        for(int i=1;i<n;i++)
        {
            if(prev>intervals[i][0])
            {
                ans++;
            }
            else
            {
                prev=intervals[i][1];
            }
        }
        return ans;
    }


};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends