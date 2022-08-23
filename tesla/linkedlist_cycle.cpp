/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        // base case
        if(head == NULL) return false;
        // slow steps
        ListNode *slow = head;
        // fast steps
        ListNode *fast = head;
        while(fast!=NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};


// TIME COMPLEXITY O(N) where N is the total number of nodes in linked list.
// SPACE COMPLEXITY O(1) where we using only two nodes.