#include<iostream>
using namespace std;

class Node
{
    public:
    int val;
    Node* next;
    Node* random;

    Node(int m_val)
    {
        val = m_val;
        next = NULL;
        random = NULL; 
    }
};

class Solution
{
    public:
    Node* copyRandomList(Node* head)
    {
        // base case
        if(head == NULL) return NULL;
        // create a pointer which points towards head
        Node* curr = head;
        while(curr != NULL)
        {
            // clone a node
            Node* new_node = new Node(curr->val);
            // insert the cloned node next to the original node
            
            new_node->next = curr->next;
            curr->next = new_node;
            curr = new_node->next;
        }
        curr = head;
        // Link the random pointers of the new nodes created
        // iterate through the newly created list and use the original nodes random pointers
        while(curr != NULL)
        {
            curr->next->random = (curr->random != NULL) ? curr->random->next : NULL;
            curr = curr->next->next;
        }
        // unweave the linked list into cloned list and the original list
        // A->B->C A'->B'->C'
        Node* old_list_ptr = head; // A->B->C
        Node* new_list_ptr = head->next; // A'->B'->C'
        Node* head_new = head->next;

        while(old_list_ptr != NULL)
        {
            old_list_ptr->next = old_list_ptr->next->next;
            new_list_ptr->next = (new_list_ptr->next != NULL) ? new_list_ptr->next->next : NULL;
            old_list_ptr = old_list_ptr->next;
            new_list_ptr = new_list_ptr->next;
        }
        return head_new;


    }
};

// TC: O(N)
// SC: O(1)

int main()
{
    return 0;
}