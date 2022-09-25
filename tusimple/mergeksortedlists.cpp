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


int main()
{
    return 0;
}