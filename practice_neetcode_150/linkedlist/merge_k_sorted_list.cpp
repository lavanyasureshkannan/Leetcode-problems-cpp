#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Input: lists = [[1,2,4],[1,3,5],[3,6]]
Output: [1,1,2,3,3,4,5,6]
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

Node* merge_k_sorted(vector<Node*>& lists)
{
    vector<int> nodes;
    for(Node* i: lists)
    {
        while(i)
        {
            nodes.push_back(i->val);
            i = i->next;
        }
    }
    sort(nodes.begin(), nodes.end());
    Node* dummy = new Node(0);
    Node* curr_node = dummy;
    for(int i: nodes)
    {
        curr_node->next = new Node(i);
        curr_node = curr_node->next;
    }
    return curr_node->next;
}


int main()
{
    vector<Node*> lists;
    Node* a1 = new Node(1);
    a1->next = new Node(2);
    a1->next->next = new Node(4);
    lists.push_back(a1);

    Node* b1 = new Node(1);
    b1->next = new Node(3);
    b1->next->next = new Node(4);
    lists.push_back(b1);
    
    Node* c1 = new Node(3);
    c1->next = new Node(6);
    lists.push_back(c1);

    merge_k_sorted(lists);
    return 0;
}
