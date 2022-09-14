#include<iostream>
#include<list>
#include<iterator>
using namespace std;

/*
    LIST: List are the sequence containers hat allow non-contiguous memory allocation. 
    As compared to vector, the list has slow traversal, 
    but once a position has been found, insertion and deletion are quick.

    List is mostly forward traversal especially in case of linkedlist

    The syntax of list is,
    list<int> list1;
*/

void display(list<int> a)
{
    list<int> :: iterator it;
    for(it = a.begin(); it != a.end(); it++)
    {
        cout << *it << " ";
    }
    cout << '\n';

}

int main()
{
    list<int>list1;
    for(int i=0; i< 10; i++)
    {
        list1.push_back(i * 2);
    }
    display(list1);
    // get the first and last elements in the list
    cout << "First element in the list: " << list1.front() << endl;
    cout << "Last element in the list: " << list1.back() << endl;
    
    // reverse
    list1.reverse();
    display(list1);

    // sort the list
    list1.sort();
    display(list1);
    return 0;
}