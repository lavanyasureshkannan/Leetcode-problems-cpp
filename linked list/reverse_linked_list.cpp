#include<iostream>
#include<vector>
using namespace std;

// create a linked list struct
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};

};

// ITERATIVE APPROACH
class Solution 
{
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode *prev = NULL;
        // 0 1 2 3 
        while(head != NULL)
        {
            // saving it in the local variable
            ListNode *next_node = head->next;
            // 0->1->2->3
            // head = 1 
            head->next = prev;
            // 0<-1->2->3
            prev = head;
            // prev = 1
            head = next_node;
            // head = 2
            // as loop continues till head is not equal to null
        }
        return prev;
        
    }
};

// TC: O(N) -> length of linkedlist
// SC: O(1)


// RECURRSIVE APPROACH

class Solution
{
    public:
    ListNode* reverseList(ListNode* head)
    {
        if(head == NULL || head->next == NULL) return head;
        ListNode* dummy = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return dummy;
    }
};

// TC: O(N)
// SC: O(N)
