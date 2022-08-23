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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        // traverse the linked lists and collect the values of the nodes into an array
        vector<int> new_arr;
        for(int i =0; i< lists.size(); i++)
        {
            ListNode* head = lists[i];
            while(head != NULL)
            {
                new_arr.push_back(head->val);
                head = head->next;
            }
        }
        // sort the array
        sort(new_arr.begin(), new_arr.end());
        
        ListNode *ans = new ListNode();
        ListNode* temp = ans;
        for(int i=0; i<new_arr.size(); i++)
        {
            temp->next = new ListNode(new_arr[i]);
            temp = temp->next;
        }
        return ans->next;
    }
};

// TC: O(Nlogk) k-> number of linked lists
// SC: O(1)

  
