//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        // code here
        
        sort(arr.begin(),arr.end());
        int count=0;
        for(int i=arr.size()-1;i>=2;i--){
            
            for(int j =i-1;j>=1;j--){
                for(int k=j-1;k>=0;k--){
                    if(arr[i]<arr[j]+arr[k] && j!=k ){
                        count++;
                    }else{
                        break;
                    }
                    
                }
            }
        
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.countTriangles(a) << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends