#include<iostream>
#include<iterator>
#include<vector>
using namespace std;

/*
ITERATOR: Iterator is a pointer which points to the memory address of the stl conatiner.
OPERATION OF THE ITERATORS: 
1. begin() -> return the beginning position
2. end() -> return the end position
3. advance() -> This increments the iterators position
4. next() -> This function returns the new iterator that the iterator would point after advancing the positions mentioned in its arguments.
5. prev() -> This function returns the new iterator that the iterator would point after decrementing the positions mentioned in its arguments.
*/


int main()
{
    vector<int> a = {1,2,3,4,5,6};
    // 1,2
    vector<int> :: iterator ptr;
    for(ptr = a.begin(); ptr < a.end(); ptr++)
    {
        cout << *ptr << " " ;
    }

    // // 3
    vector<int> b = {2,4,6,8,0};
    vector<int> :: iterator ptr2 = b.begin();
    advance(ptr2, 1); // output will be 4
    cout << *ptr2 << endl;

    // 4,5
    vector<int> c = {3,6,9,12,15,18};
    vector<int> :: iterator ptr3 = c.begin();
    vector<int> :: iterator ptr4 = c.end(); 
    auto i = next(ptr3, 3); // output will be 12
    auto j = prev(ptr3, 3); // output will be 6
    cout << *i << endl;
    cout << *j << endl;

    return 0;
}