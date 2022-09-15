// 141. Linked List Cycle

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;


struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x) , next(NULL) {};
};

// APPROACH 1 -> using vector array to keep track of the visited nodes
class Solution 
{
    public:
    bool hasCycle(ListNode *head) 
    {
        vector<ListNode*> visited;
        while (head){
            if (find(visited.begin(),visited.end(),head)!=visited.end())
                return true;
            else{
                visited.push_back(head);
                head = head->next;
            }
        }
        return false; 
        
    }
};

// TIME COMPLEXITY - O(N) -> visiting all the nodes atleast once
// SPACE COMPLEXITY - O(N) -> visited vector

//****************************************************************************************************************

//2. APPROACH 2
//Floyd's Cycle Finding Algorithm

class Solution 
{
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


//**************************************************************************************************************

// 3. APPROACH 3
// Using unordered_set 


class Solution
{
    public:
    bool hasCycle(ListNode* head)
    {
        unordered_set<ListNode*> visited;
        while(head)
        {
            if(visited.find(head) == visited.end())
            {
                visited.insert(head);
                head = head->next;
            }
            else return false; 


        }
        return true;
    }
};

// TC: O(N)
// SC: O(N)
//*********************************************************************************************************