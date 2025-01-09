//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int n = arr.size();
        int i = 0;
        int j=i+1;
        int sum = arr[0];
        
        if(arr.size()==1){
            return {-1};
        }
        
        while(i<n && j<n){
            //handled the scenario if first element is equal to target
           // because we are starting "j" from "i+1"
            if(arr[i]==target){
                return {i+1,i+1};
            }
            
            sum += arr[j];
            
            if(sum>target){
                
                i++;
                sum = arr[i];

                //handled the scenario if last element is equal to target
                // because everytime we are increasing "j" from "i+1"
                //if "sum > target"
                if(sum == target){
                    return {i+1,i+1};
                }
       
                j = i+1;
            }
            else if(sum==target){
                return {i+1,j+1};
            }
            else{
                j++;
                
            }
        }
        
        return {-1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends