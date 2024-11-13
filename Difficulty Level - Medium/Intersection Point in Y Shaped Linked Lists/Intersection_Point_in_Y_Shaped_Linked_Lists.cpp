#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
vector<int> take() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    return arr;
}
Node* inputList(int size, vector<int> v) {
    if (size == 0)
        return NULL;
    int val = v[0];
    Node* head = new Node(val);
    Node* tail = head;
    for (int i = 0; i < size - 1; i++) {
        val = v[i + 1];
        tail->next = new Node(val);
        tail = tail->next;
    }
    return head;
}
class Solution {
  public:
    int intersectPoint(Node* head1, Node* head2) {
        int len1=0;
        int len2=0;
        Node* root1=head1;
        Node* root2=head2;
        while(root1)
        len1++,root1=root1->next;
        while(root2)
        len2++,root2=root2->next;
            root1=head1;
            root2=head2;
            int len_diff=abs(len1-len2);
        
        if(len1>len2){
            while(len_diff){
                root1=root1->next;
                len_diff--;
            }
        }
        else if(len2>len1){
            while(len_diff)
            len_diff--,root2=root2->next;
        }
        while(root1 && root2){
            if(root1==root2)
            return root1->data;
            root1=root1->next;
            root2=root2->next;
        }
        return -1;
    }
};
int main() {
    srand(time(0));
    int T, n1, n2, n3;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> v1 = take();
        vector<int> v2 = take();
        vector<int> v3 = take();
        int n1 = v1.size(), n2 = v2.size(), n3 = v3.size();

        Node* head1 = NULL;
        Node* head2 = NULL;
        Node* common = NULL;

        head1 = inputList(n1, v1);
        head2 = inputList(n2, v2);
        common = inputList(n3, v3);

        Node* temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;
        Solution ob;
        cout << ob.intersectPoint(head1, head2) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends