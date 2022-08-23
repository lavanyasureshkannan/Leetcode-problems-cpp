/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
    public:
    ListNode* detectCycle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        // check for cycle
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow -> next;
            fast = fast->next->next;
            if(slow == fast) // says there is a cycle
            {
                slow = head; // MAKE NEW HEAD
                
                while(slow != fast) // find the index
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;

    }
};


// TIME COMPLEXITY -> O(N)
// SPACE COMPLEXITY -> O(1)