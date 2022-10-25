#include<iostream>
#include <queue>
#include <unordered_set>
using namespace std;

vector<vector<int>> grid;
vector<vector<int>> filter;
vector<vector<int>> result;

vector<vector<int>> convolution(vector<vector<int>> grid, vector<vector<int>> filter)
{
for(int i=0; i<grid.size(); i++)
{
    for(int j=0; j<grid[i].size();j++)
    {
        result[i][j] = grid[i][j] * filter[i][j];
    }
}
cout << result;
return result;
}
class Node
{
    public:
    int value;
    Node* next;
};

void display(Node* n)
{
    while(n!=NULL)
    {
        cout << n->value <<endl;
        n = n->next;
    }
}

void insert_element_front(Node** head, int front_val)
{
    // create an new Node
    Node* new_Node = new Node();
    new_Node->value = front_val;

    // add this node in front of the existing list
    new_Node->next= * head;

    //now the head the newly added node
    *head = new_Node;
}



int main()
{
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    head->value = 1;
    second->value = 2;
    third->value = 3;

    convolution({{1,2,3},{4,5,6},{7,8,9}},{{1,1,1},{1,1,1},{1,1,1}});
}
