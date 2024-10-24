#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkSorted(vector<int> &arr)
    {
        int ch = 2; 
        for (int i = 0, p = 1; i < (arr.size() + 1) / 2; i++, p++)
        {
            while (p != arr[i] && ch > 0)
            { 
                swap(arr[i], arr[arr[i] - 1]);
                ch--; 
            }
        }
        
        return (ch == 2) || (ch == 0 && is_sorted(arr.begin(), arr.end()));
    }
};
int main()
{
    vector<int> arr = {3, 1, 2, 4}; 
    Solution ob;                    
    bool ans = ob.checkSorted(arr); 
    if (ans)
    {
        cout << "Yes" << endl; 
    }
    else
    {
        cout << "No" << endl; // Output if the array cannot be sorted
    }
    return 0;
}
