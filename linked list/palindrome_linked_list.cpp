
#include<iostream>
#include<vector>
using namespace std;


//Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//APPROACH 1 - BY USING ARRAY
class Solution 
{
public:
    bool isPalindrome(ListNode* head) {
        // 1. create an array out of the linked list.
        vector<ListNode*>a;
        while (head)
        {
            a.push_back(head);
            head = head-> next;
        }
        //2.use two pointers from left and right to check if its equal
        int j = a.size() - 1;
        for (int i =0; i <a.size()/2; i++)
        {
            if (a[i]->val != a[j]->val)
                return false;
            j--;
        }
        return true;
        
         
    }
    
};

// TIME COMPLEXITY O(N) -> ITERATING THROUGH THE ARRAY
// SPACE COMPLEXITY O(N) -> ARRAY


//******************************************************************************************************************************************************


// 2. APPROACH 2 USING SLOW, FAST POINTER TECHNOQUE
class Solution 
{
public:
    bool isPalindrome(ListNode* head) 
    {
        ListNode* slow = head;
        ListNode* fast = head;
        
        // finding the end of the first half
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // now set fast to head and slow will be at the middle
        // 1->2-3-> 1->2->3
        // head  1   reverse 
        slow = reverselinkedlist(slow);
        fast = head;
        
        // iterate invidually
        while(slow != NULL)
        {
            // we are checking if slow is equal or not equal to fast
            if(slow->val != fast->val) return false;
            slow = slow->next;
            fast = fast ->next;
        }
        return true;
        
    }
    
    // to reverse the linked list
    ListNode* reverselinkedlist(ListNode* head)
    {
        ListNode* prev = NULL;
        while(head != NULL)
        {
            ListNode* next_node = head->next;
            head->next = prev;
            prev = head;
            head = next_node;
        }
        return prev;    
        
    }
    
};


// TIME COMPLEXITY O(N)
// SPACE COMPLEXITY O(1)


