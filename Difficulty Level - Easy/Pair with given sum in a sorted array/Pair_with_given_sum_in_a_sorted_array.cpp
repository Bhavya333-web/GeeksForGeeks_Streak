//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int i=0; int j=arr.size()-1; int count=0;
        while(i<j){
            if((arr[i]+arr[j])>target){
                j--;
            }else if((arr[i]+arr[j])<target){
                i++;
            }else{
                count++;
                int ii=i+1;int jj=j-1;
                while(ii<j && arr[ii]==arr[i]){count++;ii++;};
                while(jj>i && arr[jj]==arr[j]){count++;jj--;};
                i++;
                j--;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends