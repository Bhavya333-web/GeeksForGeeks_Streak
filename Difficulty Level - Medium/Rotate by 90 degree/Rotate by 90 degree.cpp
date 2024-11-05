#include <bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int> >& mat) {
    int n =mat.size();
    for(int i =0;i<n;i++){
        for(int j =0;j<i;j++){
            swap(mat[i][j],mat[j][i]);
        }
    } 
    for(int i=0;i<n;i++){
        reverse(mat[i].begin(),mat[i].end());
    } 
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > matrix(n);
        for (int i = 0; i < n; i++) {
            matrix[i].resize(n);
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; j++)
                cout << matrix[i][j] << " ";
            cout << "\n";
        }
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends