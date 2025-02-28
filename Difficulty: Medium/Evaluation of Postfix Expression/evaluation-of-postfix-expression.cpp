//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        stack<int> st;
        
        int n = arr.size();
        
        for(int i = 0;i<n;i++){
            if((arr[i] != "+") && (arr[i] != "-") && (arr[i] != "*") && (arr[i] != "/")){
                st.push(stoi(arr[i]));
            }else{
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                
                if(arr[i] == "+"){
                    st.push(y+x);
                }else if(arr[i] == "-"){
                    st.push(y-x);
                }else if(arr[i] == "*"){
                    st.push(y*x);
                }else{
                    st.push(y/x);
                }
            }
        }
        
        return st.top();
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends