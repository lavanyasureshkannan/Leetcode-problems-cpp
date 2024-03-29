#include<iostream>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
    public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        // find the length of the node
        int length = 0;
        ListNode *currentNode = head;
        while(currentNode != NULL)
        {
            currentNode = currentNode->next;
            length ++;
        }
        // find the node to be removed.
        // we should find the node before the nodetoberemoved node and connect it to the next node
        // 1 2 3 4 5 and n = 2 
        //then length =5 
        // length - n = 3 which is 4 (that is need to be removed)
        // since we need to find the before node we can say nodetoberemovebef = length - n -1
        if (length == n)
        {
            return head->next;
        }
        int nodetobe_removed_bef = length - n -1;
        currentNode = head;
        for(int i =0;i < nodetobe_removed_bef ; i++)
        {
            currentNode = currentNode->next;
        }
        // once you found the node to be removed connect the previous node to the next of next node.
        currentNode->next = currentNode->next->next;
        return head;
    }
};

// TIME COMPLEXITY O(N)
// SPACE COMPLEXITY O(1)