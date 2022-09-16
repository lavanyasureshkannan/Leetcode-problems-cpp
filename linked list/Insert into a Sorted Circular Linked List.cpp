#include<iostream>
using namespace std;

class Node
{
    public:
    int val;
    Node* next; 

    Node() {};
    Node(int m_val)
    {
        val = m_val;
        next = NULL;
    }
    Node(int m_val, Node* m_next)
    {
        val = m_val;
        next = m_next; 
    }
};

class Solution
{
    public:
    Node* insert(Node* head, int insertVal)
    {
        // convert insert value (int) -> node
        Node* node_insert = new Node(insertVal);
        // base case when head is null
        if(head == NULL)
        {
            node_insert->next = node_insert;
            return node_insert; 
        }
        // assume your current ptr in your head
        Node* curr = head;
        // check if the value can be inserted in the correct range
        while(curr->next != head)
        {
            // check for the values to insert the node
            int curr_val = curr->val;
            int next_val = curr->next->val;
            // checking if the value to be added in the right place
            if(curr_val <= insertVal && insertVal <= next_val)
            {
                break;
            }
            else if(curr_val > next_val)
            {
                if(curr_val >= insertVal && next_val >= insertVal) break;
                if(curr_val <= insertVal && next_val <= insertVal) break;
                
            }
            curr = curr->next;
        }
        
        // swap
        Node* temp = curr->next;
        curr->next = node_insert;
        node_insert->next = temp;
        return head; 
          
    }
};

// TC: O(n) coz traversing only once
// SC: O(1) constant


int main()
{
    return 0;
}
