#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node *prev, *next;
};
struct Node* getNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}
void printList(struct Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        Node* curr = head;
        if(curr->data > x || curr == NULL){
            Node* newNode = new Node;
            newNode->data = x;
            newNode->prev = NULL;
            newNode->next = curr;
            
            if(curr != NULL){
                curr->prev = newNode;
            }
            return newNode;
        }
        while(curr->next != NULL && curr->next->data < x){
        curr = curr->next;
        }
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = curr->next;
        newNode->prev = curr;
        if(curr->next != NULL){
            curr->next->prev = newNode;
        }
        curr->next = newNode;
        return head;
    }
};
int main() {
    int t;
    cin >> t;
    cin.ignore(); 
    while (t--) {
        string input;
        getline(cin, input); 
        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;
        if (ss >> x) {
            head = getNode(x);
            tail = head;
        }
        while (ss >> x) {
            tail->next = getNode(x);
            tail->next->prev = tail;
            tail = tail->next;
        }
        int valueToInsert;
        cin >> valueToInsert;
        cin.ignore(); 
        Solution obj;
        head = obj.sortedInsert(head, valueToInsert);
        printList(head);
    }
    return 0;
}