#include <iostream>
using namespace std;

class Node
{
    public:
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
    while(head != nullptr)
    {
        cout << head->val << "->";
        head = head->next;
    }
}

int main()
{
    Node* head = new Node(3);
    head->next = new Node(5);
    head->next->next = new Node(7);
    head->next->next->next = new Node(9);
    display(head);
    return 0;
}