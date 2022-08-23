/**
IDEA:-
There are three steps for this:
STEP 1:-
You are given this linked list:-
7->13->11->10->1->null
Now in this step we need to make this list.
7->7->13->13->11->11->10->10->1->1->null
where the bold ones are the new nodes created and added in the given linked list.
(For coding steps refer to code step 1 portion)

STEP 2:-
7->7->13->13->11->11->10->10->1->1->null
In the above linked list we have set the next pointer of the new nodes but their randoms are not yet.
So to provide them their randoms addresses, we take two pointers curr and nhead which are initialised with head and nhead(nhead is the head pointer of the cloned linked list).and we traverse through the above list and make following primal change:

ncurr->random=curr->random->next;


in order to assign the random of a new node(PLS refer code for fully understanding the loop in step 2 portion)

STEP 3:-
7->7->13->13->11->11->10->10->1->1->null
Now from the above list we have to separate out old list and new list and it will become like this:.
7->13->11->10->1->null
(PLS refer the code for understanding the code)

T.C:- O(N) S.C:- O(1).
where N is the number of nodes in the given linked list
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr){
            return nullptr;
        }
        Node* nhead=nullptr;
        Node* curr=head;
        
        //STEP 1
        while(curr!=nullptr){
            Node* temp=curr->next;
            Node* ncurr=new Node(curr->val);
            if(nhead==nullptr){
                nhead=ncurr;
            }
            curr->next=ncurr;
            ncurr->next=temp;
            curr=temp;
        }
        
        //STEP 2
        curr=head;
        Node* ncurr=nhead;
        while(curr!=nullptr && ncurr->next!=nullptr){
            if(curr->random==nullptr){
                ncurr->random=nullptr;    
            }else{
                ncurr->random=curr->random->next;
            }
            curr=curr->next->next;
            ncurr=ncurr->next->next;
        }
        if(curr->random==nullptr){
            ncurr->random=nullptr;    
        }else{
            ncurr->random=curr->random->next;
        }
        
        //STEP 3
        curr=head;
        ncurr=nhead;
        while(curr!=nullptr && ncurr->next!=nullptr){
            curr->next=ncurr->next;
            curr=ncurr->next;
            
            ncurr->next=curr->next;
            ncurr=curr->next;
        }
        curr->next=nullptr;
        
        
        return nhead;
    }
};