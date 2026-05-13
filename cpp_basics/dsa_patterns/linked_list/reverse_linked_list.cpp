#include <iostream>
using namespace std;

/*
    input => head = [1,2,3,4,5]
    output => [5,4,3,2,1]
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

void display(Node* head)
{
    while(head)
    {
        cout << head->val << "-> ";
        head = head->next;
    }
}

Node* reverseLinkedlist(Node* head)
{
    Node* dummy = new Node(0);
    while(head)
    {
        Node* next_node = head->next; // 2
        head->next = dummy->next; // 1
        dummy->next = head;
        head = next_node;
    }
    display(dummy->next);
    return dummy->next;
}



int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    reverseLinkedlist(head);
    return 0;
}