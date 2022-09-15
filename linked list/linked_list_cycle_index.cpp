#include<iostream>
#include<unordered_set>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {};
};

class Solution
{
    public:
    ListNode* detectCycle(ListNode* head)
    {
        unordered_set<ListNode*>visited;
        while(head != NULL)
        {
            if(visited.find(head) == visited.end())
            {
                visited.insert(head);
                head = head->next;
            }
            else
            {
                return head;
            }
        }
        return NULL;
    }
};


// TC: O(N)
// SC: O(N) -> unordered_set



//*************************************************************************************************************************


// cycle floyd 
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

// TC: O(N)
// SC: O(1)

int main()
{
    return 0;
}
