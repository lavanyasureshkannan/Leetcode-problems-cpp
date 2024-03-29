#include<iostream>
using namespace std;

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

// POINTERS APPROACH

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        // Base case
        if(head == NULL) return NULL;
        // seperating the linkedlist into two
        ListNode* odd = head;
        //the even node is next to head
        ListNode* even = head->next;
        // evenhead will be your starting even number
        ListNode* evenHead = even;
        
        while(even != NULL && even->next !=NULL)
        {
            // updating with odd node
            odd->next = even->next;
            odd = odd->next;
            // updating with even nodes
            even->next = odd->next;
            even = even->next;
        }
        // last node 
        odd->next = evenHead;
        return head;
    }
};


// TIME COMPLEXITY O(n) -> n is the total number of nodes.
// SPACE COMPLEXITY O(1) -> we need four pointers