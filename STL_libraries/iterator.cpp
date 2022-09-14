#include<iostream>
#include<iterator>
#include<vector>
using namespace std;

/*
ITERATOR: Iterator is a pointer which points to the memory address of the stl conatiner.
OPERATION OF THE ITERATORS: begin() -> return the beginning position
                            end() -> return the end position
*/


int main()
{
    vector<int> a = {1,2,3,4,5,6};
    vector<int> :: iterator ptr;
    for(ptr = a.begin(); ptr < a.end(); ptr++)
    {
        cout << *ptr << " ";
    }
    return 0;
}