#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);
    Node* root = newNode(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if (currVal != "N") {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];
        if (currVal != "N") {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}
class Solution {
  public:
    void solve(Node* root,vector<int> &ans,int temp){
        if(root==NULL){
         return;   
        }
         temp = (10*temp) + root->data;
        if(root->left == NULL && root->right == NULL){
            ans.push_back(temp);
        }
        solve(root->left,ans,temp);
        solve(root->right,ans,temp); 
    }
    int treePathsSum(Node *root) {
       vector<int> ans;
       int count = 0,temp = 0;
       solve(root,ans,temp);
       for(auto i:ans){
           count +=i;
       }
       return count;
    }
};
int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.treePathsSum(root);
        cout << endl;
        cout << "~\n";
    }
    return 0;
}