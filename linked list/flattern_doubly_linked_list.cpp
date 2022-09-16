#include<iostream>
using namespace std;

class Node 
{
    public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


/*
    iterate and changing all the four pointers if you find child node
*/

class Solution 
{
    Node* flattern_recurrsion(Node* head)
    {
        Node* curr = head;
        Node* tail = head;
        // iterate till your curr is not equal to null
        while(curr != NULL)
        {
            // find the child node
            Node* child = curr->child;
            Node* next = curr->next;
            if(child)
            {
                // if child is found then call the rec function
                Node* _tail = flattern_recurrsion(child);

                _tail->next = next;
                if(next != NULL)
                {
                    next->prev = _tail;
                }

                curr->next = child;
                child->prev = curr;

                curr->child = nullptr;

                curr = tail;
            }
            else
            {
                // if no child then keep incrementing your child
                curr = next; 
            }
            if(curr) tail = curr;
        }
        return tail;
    } 

public:
    Node* flatten(Node* head) 
    {
        if(head) 
        {
            flattern_recurrsion(head);
        }
        return head;
    }
};

// TC: O(N) -> length of the linked list
// SC: O(N) -> recurrsive calls made on child nodes


int main()
{
    return 0;
}