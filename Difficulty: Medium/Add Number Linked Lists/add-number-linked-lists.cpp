//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
     Node* reverse(Node* root){
      Node* ptr=NULL;
      while(root){
          Node* nxt=root->next;
          root->next=ptr;
          ptr=root;
          root=nxt;
      }
      return ptr;
  }
    Node* addTwoLists(Node* num1, Node* num2) {
          Node* rev1=reverse(num1);
          Node* rev2=reverse(num2);
         
          Node* res=new Node(-1);
          int carry=0;
          Node* ptr=res;
          while(rev1 && rev2){
              int ele=rev1->data+rev2->data+carry;
              ptr->next=new Node(ele%10);
              carry=ele/10;
              rev1=rev1->next;
              rev2=rev2->next;
              ptr=ptr->next;
          }
          while(rev1){
              int ele=rev1->data+carry;
              ptr->next=new Node(ele%10);
              carry=ele/10;
              rev1=rev1->next;
              ptr=ptr->next;
          }
          while(rev2){
              int ele=rev2->data+carry;
              ptr->next=new Node(ele%10);
              carry=ele/10;
              rev2=rev2->next;
              ptr=ptr->next;
          }
          while(carry){
              ptr->next=new Node(carry%10);
              carry/=10;
          }
          Node* ans=reverse(res->next);
          while(ans->data==0)
          ans=ans->next;
          return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends