#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int mergeAndCount(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
        int i = left;     
        int j = mid + 1;  
        int k = left;     
        int invCount = 0; 
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                invCount += (mid - i + 1); 
            }
        }

        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        // Copy remaining elements of right subarray (if any)
        while (j <= right) {
            temp[k++] = arr[j++];
        }

        // Copy merged elements back into the original array
        for (int i = left; i <= right; i++) {
            arr[i] = temp[i];
        }

        return invCount;
    }

    int mergeSortAndCount(vector<int>& arr, vector<int>& temp, int left, int right) {
        int invCount = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;

            
            invCount += mergeSortAndCount(arr, temp, left, mid);

            invCount += mergeSortAndCount(arr, temp, mid + 1, right);

            invCount += mergeAndCount(arr, temp, left, mid, right);
        }
        return invCount;
    }

    int inversionCount(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp(n);
        return mergeSortAndCount(arr, temp, 0, n - 1);
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends