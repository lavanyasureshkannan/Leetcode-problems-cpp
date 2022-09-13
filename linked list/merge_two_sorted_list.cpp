#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};


// APPROACH 1 : ITERATIVE

class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        /*
        1. base case : what is one node is null
        2. create a dummy node -> update the node
        3. while loop till both nodes are not null(comparision l1 and l2)
        4. remaining nodes -> size of the lists are different
        */

       if(l1 == NULL) return l2;
       if(l2 == NULL) return l1;

       ListNode* dummy = new ListNode(0);
       ListNode* curr_Node = dummy;

    
       while(l1 != NULL && l2 != NULL)
       {
        if(l1->val <= l2->val)
        {
            curr_Node->next = l1;
            l1 = l1->next;
        }
        else
        {
            curr_Node->next = l2;
            l2 = l2->next;
        }

        curr_Node = curr_Node->next;
       }
        if(l1 != NULL) 
        {
            curr_Node->next = l1;
            l1 = l1->next;
        }
        if(l2 != NULL)
        {
            curr_Node->next = l2;
            l2 = l2->next;
        }


       return dummy->next;

    }
};

// TC: O(n + m) -> because we are checking two loops  
// SC: O(1) 



// APPROACH 2: RECURRSIVE
class Solution
{
    public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        /*
        Compare the heads of l1 and l2
        */
       if(l1 == NULL) return l2;
       if(l2 == NULL) return l1;

       if(l1->val < l2->val)
       {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
       }
       else
       {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
       }
    }
};

// TC: O(n + m)
// SC: O(1)

int main()
{
    return 0;
}