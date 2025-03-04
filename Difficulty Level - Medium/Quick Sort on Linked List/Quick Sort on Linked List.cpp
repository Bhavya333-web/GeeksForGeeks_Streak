#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
void push(struct Node*& head_ref, int new_data) {
    struct Node* new_node = new Node(new_data);
    new_node->next = head_ref;
    head_ref = new_node;
}
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
class Solution {
  public:
    struct Node* partition(struct Node* head, struct Node* last){
      struct Node* i = head;
      struct Node* j = head->next;
      while(j!=last){
          if(j->data<head->data){
              i=i->next;
              swap(i->data,j->data);
          }
          j=j->next;
      }
      swap(i->data,head->data);
      return i;
  }
  void Quick_Sort(struct Node* head, struct Node* last){
      if(head == last || head->next == last){
          return;
      }
      struct Node* p = partition(head,last);
      Quick_Sort(head,p);
      Quick_Sort(p->next,last);
  }
    struct Node* quickSort(struct Node* head) {
        Quick_Sort(head,NULL);
        return head;
    }
};
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
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.quickSort(head);

        printList(head);
        cout << "~" << endl;
    }
    return 0;
}