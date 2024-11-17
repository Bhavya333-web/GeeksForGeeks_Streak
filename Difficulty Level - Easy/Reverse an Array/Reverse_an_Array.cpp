#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
class Solution {
public:
    void swap(vector<int>& arr, int i, int j) {
        int val = arr[i];
        arr[i] = arr[j];
        arr[j] = val;
    }
    void reverseArray(vector<int>& arr) {
        int i = 0, j = arr.size() - 1;
        while (i <= j) {
            swap(arr, i, j);
            i++;
            j--;
        }
    }
};
int main() {
    int tc;
    cin >> tc;
    cin.ignore(); 
    while (tc-- > 0) {
        string line;
        getline(cin, line); // Read the entire line of numbers
        stringstream ss(line);

        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution obj;
        obj.reverseArray(arr);

        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}
