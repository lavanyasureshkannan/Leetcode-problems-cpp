#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node(int m_val)
    {
        val = m_val;
        next = nullptr;
    }
};

class LinkedList
{
    public:
    Node* head;
    Node* tail;
    size_t node_size;

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        node_size = 0;
    }

    bool isEmpty() { return head == nullptr;}
    size_t ll_size() { return node_size;}

    void add_at_tail(int val)
    {
        Node* new_node = new Node(val);
        if(tail)
        {
            tail->next = new_node;
            tail = new_node;    
        }
        else
        {
            head = tail = new_node;
        }
        node_size ++;
    }

    void add_at_head(int val)
    {
        Node* prev = new Node(val);
        if(head)
        {
            prev->next = head;
            head = prev;
        }
        node_size ++;
    }

    void add_at_index(int index, int val)
    {
        Node* add_node = new Node(val);
        Node* curr = head;
        for(int i=0; i<index-1; i++)
        {
            curr = curr->next;
        }
        add_node->next = curr->next;
        curr->next = add_node;
        node_size++;

    }

    void delete_at_index(int index)
    {
        
        // if index is 0 -> then delete head
        if(index == 0)
        {
            Node* temp = head;
            head->next = nullptr;
            if(head == nullptr) { tail == nullptr;}
            delete temp;
        }
        Node* curr = head;
        for(int i=0; i<index-1; i++)
        {
            Node* curr = curr->next;
        }
        Node* target = curr->next;
        curr->next = target->next;
        if(target == tail) tail = curr;
        delete target;
        node_size--;
    }

    void display()
    {
        Node* curr = head;
        while(curr)
        {
            cout << curr->val << "->";
            curr = curr->next;
        }   
    }
};

int main()
{
    LinkedList ll;
    ll.add_at_tail(1);
    ll.add_at_tail(2);
    ll.add_at_tail(3);
    ll.display();
    cout << endl;
    ll.add_at_head(0);
    ll.display();
    cout << endl;
    ll.add_at_index(2, 4);
    ll.display();
    cout << endl;
    ll.delete_at_index(3);
    ll.display();
    
    // cout << ll.ll_size() << endl;
}