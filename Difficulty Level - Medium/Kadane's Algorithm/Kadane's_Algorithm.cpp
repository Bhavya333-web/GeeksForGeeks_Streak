#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int current=arr[0];
        int result=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            current=max(arr[i]+current,arr[i]);
            result=max(current,result);   
        }
        return result;
    }
};
int main() {
    int t;
    cin >> t;
    cin.ignore(); 
    while (t--)   
    {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl;
    }
}