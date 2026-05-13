#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Input: head = [3,2,0,-4], pos = 1
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

bool hasCycle(Node* head)
{
    vector<Node*> visited;
    while(head)
    {
        if(find(visited.begin(), visited.end(), head) != visited.end()) return true;
        else
        {
            visited.push_back(head);
            head = head->next;
        }
    }
    return false;
}

bool hascycyle_floyd(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(-4);
    
    head->next->next->next->next = head->next;

    cout << hasCycle(head) << endl;
    cout << hascycyle_floyd(head) << endl;
    return 0;
}