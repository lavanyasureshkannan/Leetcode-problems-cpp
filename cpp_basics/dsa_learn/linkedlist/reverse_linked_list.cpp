#include <iostream>

struct Node
{
    int val;
    Node* next;

    Node(int m_val)
    {
        m_val = val;
        next = nullptr;
    }
};

void print_linkedlist(Node* head)
{
    while(head != nullptr)
    {
        std::cout << head->val << "->";
        head = head->next;
    }
}

Node* reverselinkedlist(Node* head)
{
    Node* prev = new Node(0);
    while(head != nullptr)
    {
        Node* next_node = head->next; //2
        head->next = prev->next; // 1
        prev->next = head;
        head = next_node;
        
    }
    print_linkedlist(head);
    return head;
}


int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    reverselinkedlist(head);
    return 0;
}