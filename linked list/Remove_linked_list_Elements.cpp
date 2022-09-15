#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {};
};

class Solution
{
    public:
    ListNode* removeElements(ListNode* head, int val)
    {
        // BASE CASE
        while(head != NULL && head->val == val)
        {
            head = head->next;
        }
        ListNode* curr_node = head;
        while(curr_node != NULL && curr_node->next != NULL)
        {
            if(curr_node->next->val == val)
            {
                curr_node->next = curr_node->next->next;
            }
            else 
            {
                curr_node = curr_node->next;
            }
        }
        return head;
    }

};

// TC: O(N)
// SC: O(1) 


int main()
{
    return 0;
}