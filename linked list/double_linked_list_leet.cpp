
#include<iostream>
class MyLinkedList 
{
public:
    struct node
    {
        int data;
        node* next;
        node* prev;
    };
    
    node* head;
    node* tail;
    int size;
    
    /** Initialize your data structure here. */
    MyLinkedList() 
    {
        head = new node();
        tail = new node();
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) 
    {
        if(index >= size)
            return -1;
        else
        {
            node* curr = head->next;
            while(index != 0)
            {
                curr = curr->next;
                index--;
            }
            return curr->data;
        }
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) 
    {
        node* next = head->next;
        node* addNode = new node();
        addNode->data = val;
        addNode->next = next;
        addNode->prev = head;
        head->next = addNode;
        next->prev = addNode;
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) 
    {
        node* prev = tail->prev;
        node* addNode = new node();
        addNode->data = val;
        addNode->next = tail;
        addNode->prev = prev;
        prev->next = addNode;
        tail->prev = addNode;
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) 
    {
        if(index > size)
            return;
        else if(index == size)
            addAtTail(val);
        else if(index == 0)
            addAtHead(val);
        else{
            node* curr = head;
            while(index != 0)
            {
                curr = curr->next;
                index--;
            }
            node* next = curr->next;
            node* addNode = new node();
            addNode->data = val;
            addNode->next = next;
            addNode->prev = curr;
            curr->next = addNode;
            next->prev = addNode;
            size++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) 
    {
        if(index >= size)
            return;
        else
        {
            node* curr = head;
            while(index != 0)
            {
                curr = curr->next;
                index--;
            }
            node* del = curr->next;
            del->next->prev = del->prev;
            del->prev->next = del->next;
            delete del;
            size--;
        }
    }
};