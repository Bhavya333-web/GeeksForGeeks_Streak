#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void sort012(vector<int>& arr) {
        int n = arr.size() ;
        int i = 0 ; 
        while(i < n && arr[i] == 0) i ++ ;
        int j = n - 1 ;
        while(j > i && arr[j] == 2) j -- ;
        int k = i ; 
        while(k <= j){
            
            while(i < k && arr[i] == 0) i ++ ;
            while(j > k && arr[j] == 2) j -- ;
            
            k = max(i , k) ;
            if(k > j) break ;
            
            if(arr[k] == 0){ swap(arr[i] , arr[k]) ; i ++ ; }
            else if(arr[k] == 2){ swap(arr[j] , arr[k]) ; j -- ; }
            else k ++ ;
            
        }
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends