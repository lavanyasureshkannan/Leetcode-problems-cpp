#include <iostream>

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


void print_ll(Node* head)
{
    while(head != nullptr)
    {
        std::cout << head->val << "->";
        head = head->next; 
    }
}


// 2->1->4->3

// step1 : 2->1->3->4
//
Node* swap_nodes(Node* head)
{
    if(head == nullptr || head->next == nullptr) return head;
    Node* dummy = new Node(0);
    dummy->next = head; // 0->1->2->3->4
    Node* prev = dummy;
    while(head && head->next)
    {
        Node* first = head; // 1
        Node* second = head->next; // 2

        first->next = second->next; //  1->3->4
        second->next = first; // 2->1->3->4
        prev->next = second; // 0->2->1->3->4

        prev = first;
        head = first->next;
    }
    return dummy->next;
}


int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head = swap_nodes(head);
    print_ll(head);
    
}