//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
   public:
    double power(double b, int e) {
        
        int p=abs(e);
        double ans=1;
        while(p){
            if(p%2==0){
                b=b*b;
                p/=2;
            }
            else{
                ans=ans*b;
                p=p-1;
            }
        }
        if(e<0)
        return 1/ans;
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends