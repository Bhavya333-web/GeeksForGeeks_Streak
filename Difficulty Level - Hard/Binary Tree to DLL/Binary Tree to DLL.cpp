#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;

    Node()
        : data(0)
        , left(NULL)
        , right(NULL) {}

    Node(int x)
        : data(x)
        , left(NULL)
        , right(NULL) {}
};
Node* newNode(int val) {
    Node* temp = new Node(val);
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
void printList(Node* node) {
    Node* prev = NULL;
    while (node != NULL) {
        cout << node->data << " ";
        prev = node;
        node = node->right;
    }
    cout << endl;
    while (prev != NULL) {
        cout << prev->data << " ";
        prev = prev->left;
    }
    cout << endl;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
    }
}
class Solution {
  public:
    void Inorder(Node* root,vector<int>&inord){
        if(!root) return;
        Inorder(root->left,inord);
        inord.push_back(root->data);
        Inorder(root->right,inord);
    }
    Node* bToDLL(Node* root) {
        vector<int>inord;
        Inorder(root,inord);
        Node *temp=new Node(-1);
        Node *ans=temp;
        for(auto &i:inord){
            Node *prev=temp;
            temp->right=new Node(i);
            temp=temp->right;
            temp->left=prev;
        }
        Node *fans=ans->right;
        fans->left=NULL;
        ans->right=NULL;
        return fans;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function */
int main() {
    int t;
    cin >> t;
    getchar();

    while (t--) {
        string inp;
        getline(cin, inp);
        Node* root = buildTree(inp);

        Solution ob;
        Node* head = ob.bToDLL(root);
        printList(head);

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends