#include<iotsream>
#include<unordered_set>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// APPROACH 1 --> unordered_set
class Solution 
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        unordered_set<ListNode*> visited_B;
        // Traverse through B and add nodes to the visited listnode
        while(headB != NULL)
        {
            visited_B.insert(headB);
            headB = headB->next; 
        }
        
        while(headA != NULL)
        {
            if(visited_B.find(headA) != visited_B.end()) return headA;
            headA = headA->next;
        }
        return NULL;

    }
};

// TIME COMPLEOXTY O(N+M) ---> O(M)-> to build and traverse through the linkedlist and O(N) --> to traverse through A 
// SPACE COMPLEXITY O(M) -> we are creating a new set


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//APPROACH 2 -> TWO POINTERS
class Solution 
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        // two pointers
        ListNode* a = headA;
        ListNode* b = headB;
        
        // traverse
        while(a != b)
        {
            // if a is pointing to null, set a to point to headB
            if(a == NULL) 
            {
                a = headB;
            }
            else
            {
                a = a->next;
            }
            // if b is pointing to null, set b to point to headA
            if(b == NULL)
            {
                b = headA;
            }
            else
            {
                b = b->next;
            }
        }
        // return the value pointed to a or b as they are equal now
        return a;
            
    }
};

// TIME COMPLEXITY O(N+M) as each list is traversed twice
// SPACE COMPLEXITY O(1) no additional data structure

//*************************************************************************************************************

