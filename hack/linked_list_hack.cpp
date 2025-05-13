#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* next;

    Node(int m_val)
    {
        val = m_val;
    }
};

void traverse_print(Node* head)
{
    while(head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
}


int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    traverse_print(head);
    return 0;
}