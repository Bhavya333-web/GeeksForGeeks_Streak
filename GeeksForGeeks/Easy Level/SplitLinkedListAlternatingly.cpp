#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
class Solution
{
public:
    vector<Node *> alternatingSplitList(struct Node *head)
    {
        vector<Node *> result;
        Node *_dummy1 = new Node(-1);
        Node *_dummy2 = new Node(-1);
        Node *temp1 = _dummy1;
        Node *temp2 = _dummy2;
        Node *temp3 = head;
        int i = 0;
        while (temp3 != nullptr)
        {
            if (i % 2 == 0)
            {
                Node *_new1 = new Node(temp3->data);
                temp1->next = _new1;
                temp1 = temp1->next;
            }
            else
            {
                Node *_new2 = new Node(temp3->data);
                temp2->next = _new2;
                temp2 = temp2->next;
            }
            i++;
            temp3 = temp3->next;
        }
        result.push_back(_dummy1->next);
        result.push_back(_dummy2->next);
        return result;
    }
};
void printList(struct Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number)
        {
            arr.push_back(number);
        }

        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;

        for (int i = 1; i < arr.size(); ++i)
        {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node *> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}
