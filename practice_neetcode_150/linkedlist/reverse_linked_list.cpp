#include <iostream>
using namespace std;

/*
Input: head = [0,1,2,3]
Output: [3,2,1,0]
*/

struct Node
{
    int val;
    Node* next;

    Node(int m_val)
    {
        val = m_val;
        next = nullptr;
    }
};

void print(Node* head)
{
    while(head)
    {
        cout << head->val << " ";
        head = head->next;
    }
}

Node* reverse_linkedlist(Node* head)
{
    Node* dummy = new Node(0); // 1->2>3->4
    while(head)
    {
        Node* new_node = head->next;
        head->next = dummy->next;
        dummy->next = head;
        head = new_node;
    }
    print(dummy->next);
    return dummy->next;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    reverse_linkedlist(head);
    return 0;
}