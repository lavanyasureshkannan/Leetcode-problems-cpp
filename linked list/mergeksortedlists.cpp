#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};

// BRUTE FORCE ALGORITHM
ListNode* mergetwosortedlists(vector<ListNode*>& lists)
{
    // 1. iterate through the linked list and save them on the array
    // 2. sort the array
    // 3. make a new linked list from the values in the array => create a dummy node, 

    vector<int> new_array;
    for(int i=0; i<lists.size(); i++)
    {
        ListNode* head = lists[i];
        while(head != NULL)
        {
        new_array.push_back(head->val);
        head = head->next;
        }
    }
    sort(new_array.begin(), new_array.end());
    ListNode* dummy = new ListNode();
    ListNode* temp = dummy;
    for(int i=0; i<new_array.size(); i++)
    {
        temp->next = new ListNode(new_array[i]);
        temp = temp->next;
    }
    return dummy->next;
};
/* 
TC: (N log N) => as is the number of nodes 
 1. collecting all the values in O(N) time
 2. sorting O(log N)
 3. recreating the linked list O(N)

SC: O(N) => for sorting and recreating O(n)
*/

// COMPARE THE TWO SORTED LISTS

class Solution
{
    private:
    ListNode* mergetwosortedlists(ListNode* lists1, ListNode* lists2)
    {
        // base cases
        if(lists1 == nullptr) return lists2;
        if(lists2 == nullptr) return lists1;
        if(lists1->val < lists2->val)
        {
            lists1->next = mergetwosortedlists(lists1->next, lists2);
            return lists1;
        }
        lists2->next = mergetwosortedlists(lists1, lists2->next);
        return lists2; 

    }
    public:
    ListNode* mergeksorted(vector<ListNode*>& lists)
    {
        // base case
        if(lists.empty()) return nullptr;
        // make a head
        ListNode* head = nullptr;
        for(ListNode* currnodes: lists)
        {
            head = mergetwosortedlists(head, currnodes);
        }
        return head;
    }
};

// TC: O(N log k) => final linkedlists
// SC: O(1) more like an inplace operation.
int main()
{
    return 0;
}