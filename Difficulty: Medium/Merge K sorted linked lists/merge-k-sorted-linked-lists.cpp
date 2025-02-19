//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    Node* merge(Node* list1,Node* list2){
        if(list1==NULL){
            return list2;
        }
        else if(list2==NULL){
            return list1;
        }
        else if(list1->data<list2->data){
            list1->next=merge(list1->next,list2);
            return list1;
        }
        else {
            list2->next=merge(list2->next,list1);
            return list2;
        }
    }
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        Node* temp=arr[0];
        if(arr.size()==1){
            return temp;
        }
        for(int i=1;i<arr.size();i++){
            temp=merge(temp,arr[i]);
        }
        return temp;
    }
};


//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->next = newNode;
                temp = temp->next;
            }
            v[i] = head->next;
        }

        Solution ob;
        Node* head = ob.mergeKLists(v);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends