//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     vector<double> getMedian(vector<int> &arr) {
        // code here
        multiset<int> ms;
        vector<double> med(arr.size());
        int x;
        multiset<int>::iterator mid;
        for(int i=0;i<arr.size();i++){
            x=arr[i];
            if(ms.empty()){
                ms.insert(x);
                mid=ms.begin();
            }
            else{
                ms.insert(x);
                if(x<*mid){
                    if(ms.size()%2==0) --mid;
                }else{
                    if(ms.size()&1) ++mid;
                }
            }
            if(ms.size()&1) med[i]=*mid;
            else{
                med[i]=(*mid+*next(mid))/2.0;
            }
        }
        return med;
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
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends