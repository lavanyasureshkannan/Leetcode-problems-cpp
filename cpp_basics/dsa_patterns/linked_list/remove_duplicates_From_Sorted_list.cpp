#include <iostream>
#include <unordered_set>
using namespace std;

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

Node* duplicates(Node* head)
{
    unordered_set<int> ss;
    while(head != nullptr)
    {
        ss.insert(head->val);
        head = head->next;
    }
    Node* dummy = new Node(0);
    Node* curr_node = dummy;
    for(int i: ss)
    {
        curr_node->next = new Node(i);
        curr_node = curr_node->next;
    }
    return dummy->next;
}

// TC: O(N) // hashset stores the element
// SC: O(N) 

Node* duplicates_optimised(Node* head)
{
    Node* curr = head;
    while(curr != NULL && curr->next != NULL)
    {
        if(curr->next->val == curr->val)
        {
            curr->next = curr->next->next;
        } 
        else
        {
            curr = curr->next;
        }
    }
    return head;
}

// TC: O(N) 
// SC: O(1) 

int main()
{
    Node* head = new Node(1);
    head->next = new Node(1);
    head->next->next = new Node(2);
    Node* res = duplicates(head);
    while(res != NULL) 
    {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}