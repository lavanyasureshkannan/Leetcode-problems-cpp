#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;

    ListNode(int x, ListNode* next) : val(x), next(next) {};
};

ListNode* rotateRight(ListNode* head, int k)
{
    if(head == NULL || head->next == NULL) return head; 
    int length = 1;
    // find the length of the linked list
    ListNode* curr = head;
    while(curr->next != NULL)
    {
        length++;
        curr = curr->next;
    }
    // the curr is pointing towards the last node.
    // making it point towards head again
    curr->next = head;
    // if k is greater than the length then make it less
    k = k % length;
    k = length - k; // pivot position
    while(k--)
    {
        // making the curr to point the next
        curr = curr->next;
    }
    head = curr->next;
    curr->next = NULL;
    return head;
}                                                    

int main()
{
    return 0;
}