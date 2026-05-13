#include <iostream>
using namespace std;

/*
Input: head = [1,2,3,4], index = 1
Output: true
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

bool detect_cycle(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next;
    return 0;
}