//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     int search(vector<int>& arr, int key) {
       int n=arr.size();
       int low=0;
       int high=n-1;
       while(low<=high){
           int mid=(low+high)/2;
           if(arr[mid]==key)
           return mid;
           else if(arr[mid]>=arr[low]){
               if(arr[mid]>=key && arr[low]<=key)
               high=mid-1;
               else
               low=mid+1;
           }
           else{
               if(arr[mid]<=key && arr[high]>=key)
               low=mid+1;
               else
               high=mid-1;
           }
       }
       return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends