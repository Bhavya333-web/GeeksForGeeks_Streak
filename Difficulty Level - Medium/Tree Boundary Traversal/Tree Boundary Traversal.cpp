#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000
struct Node
{
    int data;
    Node* left;
    Node* right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
Node* buildTree(string str)
{
    if(str.length() == 0 || str[0] == 'N')
        return NULL;
    vector<string> ip;
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
    Node* root = newNode(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    void traverseLeft(Node* root, vector<int>& vec) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) return;  // Fix base condition
    
    vec.push_back(root->data);
    
    if (root->left != NULL) traverseLeft(root->left, vec);
    else traverseLeft(root->right, vec);
}

void traverseLeaf(Node* root, vector<int>& vec) {
    if (root == NULL) return;
    
    if (root->left == NULL && root->right == NULL) {
        vec.push_back(root->data);
    }
    
    traverseLeaf(root->left, vec);
    traverseLeaf(root->right, vec);
}

void traverseRgt(Node* root, vector<int>& vec) {  // Correct name here
    if (root == NULL || (root->left == NULL && root->right == NULL)) return;  // Fix base condition
    
    if (root->right != NULL) traverseRgt(root->right, vec);  // Correct function call here
    else traverseRgt(root->left, vec);
    
    vec.push_back(root->data);  // Add after the recursive call to ensure reverse order
}

vector<int> boundary(Node *root) {
    vector<int> v;
    if (root == NULL) return v;
    
    v.push_back(root->data);
    
    traverseLeft(root->left, v);
    traverseLeaf(root->left, v);
    traverseLeaf(root->right, v);
    traverseRgt(root->right, v);  // Correct function call
    
    return v;
}
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends