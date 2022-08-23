/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
    // create a dummy node and make it is as the curr node for returning purpose
    ListNode* dummyhead = new ListNode(0);
    ListNode* curr = dummyhead;
    // intialise carry
    int carry = 0;
    // traverse both the linked list
    while(l1 != NULL || l2 != NULL || carry != NULL)
    {
        // add the values of the node if it is not zero
        // if l1.val is not equal to null then use l1.val else 0
        int l1_val =  (l1 != NULL) ? l1->val : 0;
        int l2_val =  (l2 != NULL) ? l2->val : 0; 
        // calculate the current sum
        int curr_sum = l1_val + l2_val + carry;
        // update the carry and the last digit
        carry = curr_sum / 10;
        int last_digit = curr_sum % 10;
        // curr should point the next digit
        curr->next = new ListNode(curr_sum % 10);
        curr = curr->next;

        // edge cases
        l1 = l1 ? l1->next : nullptr;
        l2 = l2 ? l2->next : nullptr;
    
    }
    return dummyhead->next;    
    }
};

// TC : O(max(m,n)). m and n -> length l1 and l2, max -> represents maximum iteration
// SC : O(max(m,n)). length of the new list can be max(m,n) + 1


