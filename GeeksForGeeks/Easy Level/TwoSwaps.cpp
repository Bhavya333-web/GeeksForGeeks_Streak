#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkSorted(vector<int> &arr)
    {
        int ch = 2; // Number of allowed swaps
        for (int i = 0, p = 1; i < (arr.size() + 1) / 2; i++, p++)
        {
            while (p != arr[i] && ch > 0)
            { // Keep swapping until the element is in the right position or swaps are exhausted
                swap(arr[i], arr[arr[i] - 1]);
                ch--; // Decrement swap counter
            }
        }
        // Check if the array is sorted or if the swaps were exhausted
        return (ch == 2) || (ch == 0 && is_sorted(arr.begin(), arr.end()));
    }
};

int main()
{
    vector<int> arr = {3, 1, 2, 4}; // Example input
    Solution ob;                    // Declare the Solution class object
    bool ans = ob.checkSorted(arr); // Call the checkSorted method
    if (ans)
    {
        cout << "Yes" << endl; // Output if the array can be sorted with the allowed swaps
    }
    else
    {
        cout << "No" << endl; // Output if the array cannot be sorted
    }
    return 0;
}
