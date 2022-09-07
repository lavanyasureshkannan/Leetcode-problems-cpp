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
    ListNode* swapPairs(ListNode* head)
    {
        // base case 1: if the node is null
        if(head == NULL || head->next == NULL) return head;
        // create a dummy node
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prevNode = dummy;

        while(head != NULL && head->next != NULL)
        {
            // assigning the nodes
            ListNode* firstNode = head;
            ListNode* secondNode = head->next;

            // swapping
            prevNode->next = secondNode;
            firstNode->next = secondNode->next;
            secondNode->next = firstNode;

            // reinitialisation
            prevNode = firstNode;
            head = firstNode->next;
        }
        return dummy->next;
    }
};

// TC: O(N) -> N size of linked list
// SC: O(1) 



// RECURRSION
class Solution
{
    public:
    ListNode* swapPairs(ListNode* head)
    {
        // base case
        if(head == NULL || head->next == NULL) return head;

        // nodes to be swapped
        ListNode* firstNode = head;
        ListNode* secondNode = head->next;

        // swapping recurrsively
        firstNode->next = swapPairs(secondNode->next);
        secondNode->next = firstNode;

        // head will be the second node
        return secondNode;

    }
};
//TC: O(N)->length of the linked list
// SC: O(N) -> stack space