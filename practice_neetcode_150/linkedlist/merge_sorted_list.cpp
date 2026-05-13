#include <iostream>
using namespace std;

/*
Input: list1 = [1,2,4], list2 = [1,3,5]
Output: [1,1,2,3,4,5]
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

Node* merge_sorted(Node* l1, Node* l2)
{
    // base case
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;

    // create a dummy node
    Node* dummy = new Node(0);
    Node* curr_node = dummy;

    while(l1 != NULL && l2 != NULL)
    {
        if(l1->val <= l2->val) 
        {
            curr_node->next = l1;
            l1 = l1->next;
        }
        else
        {
            curr_node->next = l2;
            l2 = l2->next;
        }
        curr_node = curr_node->next;
    }
    if(l1 != NULL)
    {
        curr_node->next = l1;
        l1 = l1->next;
    }
    if(l2 != NULL)
    {
        curr_node->next = l2;
        l2 = l2->next;
    }
    return dummy->next;
}

Node* merge_sorted(Node* l1, Node* l2)
{
    // base case
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    if(l1->val < l2->val)
    {
        l1->next = merge_sorted(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = merge_sorted(l1,l2->next);
        return l2;
    }
}

int main()
{
    return 0;
}