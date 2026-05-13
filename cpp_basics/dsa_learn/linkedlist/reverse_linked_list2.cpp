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

/*
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
*/

Node* reverse_linked_list2(Node* head, int left, int right)
{
    Node* dummy = new Node(0);
    Node* prev = dummy;
    for(int i=0; i<left; i++)
    {
        prev = prev->next;
    }
    Node* curr = prev->next;
    Node* next_node = nullptr;

    for(int i=0; i<right-left; i++)
    {
        next_node = curr->next; 
        curr->next = next_node->next; 
        next_node->next = prev->next; 
        prev->next = next_node;

    }
    return dummy->next;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    return 0;
}