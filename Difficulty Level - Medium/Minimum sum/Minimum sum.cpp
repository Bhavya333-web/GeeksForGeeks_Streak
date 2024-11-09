#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        sort( arr.begin(), arr.end(), greater<int>() );
        int n = arr.size(), sum=0;
        vector<char> v;
        for( int i=0; i<n; i+=2 ) {
            sum += arr[i];
            if( (i+1) < n )
                sum += arr[i+1];
            v.push_back( '0' + sum%10 );
            sum = sum/10;
        }
        if( sum )
            v.push_back( '0' + sum );
        while( v.back() == '0' )
            v.pop_back();
        return string( v.rbegin(), v.rend() );
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends