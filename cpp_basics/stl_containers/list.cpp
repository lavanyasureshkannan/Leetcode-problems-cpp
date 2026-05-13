#include <iostream>
#include <list>
using namespace std;

/*
    List is like a double linked list that has access to next and prev elements
*/

void printlist(list<int>& l)
{
    for(auto i : l)
    {
        cout << i << " "; 
    }
    cout << endl;
}

int main()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    l1.push_back(50);

    printlist(l1);

    // cout << l1.front() << endl;
    // cout << l1.back() << endl;
    // l1.pop_front();
    // cout << l1.front() << endl;
    // l1.pop_back();
    // cout << l1.back() << endl;

    list<int>:: iterator it = l1.begin();
    cout << *it << endl;
    ++ it;
    cout << *it << endl;
    return 0;
}