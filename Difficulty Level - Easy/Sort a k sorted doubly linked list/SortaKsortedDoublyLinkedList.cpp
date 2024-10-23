#include <bits/stdc++.h>
using namespace std;
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
struct compare {
    bool operator()(DLLNode* a, DLLNode* b) {
        return a->data > b->data;
    }
};
class Solution {
public:
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        if (head == NULL) return head;
        priority_queue<DLLNode*, vector<DLLNode*>, compare> minHeap;
        DLLNode *newHead = NULL, *last = NULL;
        for (int i = 0; head && i <= k; i++) {
            minHeap.push(head);
            head = head->next;
        }
        while (!minHeap.empty()) {
            DLLNode *minNode = minHeap.top();
            minHeap.pop();
            if (newHead == NULL) {
                newHead = minNode;
                newHead->prev = NULL;
                last = newHead;
            } else {
                last->next = minNode;
                minNode->prev = last;
                last = minNode;
            }
            if (head) {
                minHeap.push(head);
                head = head->next;
            }
        }
        last->next = NULL;

        return newHead;
    }
};
void push(DLLNode **tailRef, int new_data) {
    DLLNode *newNode = new DLLNode(new_data);
    newNode->next = NULL;

    newNode->prev = (*tailRef);
    if ((*tailRef) != NULL)
        (*tailRef)->next = newNode;

    (*tailRef) = newNode;
}

// Function to print nodes in a given doubly linked list
void printList(DLLNode *head) {
    // if list is empty
    if (head == NULL)
        return;

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// Driver
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        int k;
        cin >> k;
        cin.ignore();

        DLLNode *head = new DLLNode(arr[0]);
        DLLNode *tail = head;

        // Check if the array is empty
        for (size_t i = 1; i < arr.size(); ++i) {
            push(&tail, arr[i]);
        }
        Solution obj;
        printList(obj.sortAKSortedDLL(head, k));
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends