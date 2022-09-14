#include<iostream>
#include<set>
#include<iterator>
using namespace std;


/*

MULTISET -> Multisets are a type of associative containers similar to the set, with the exception that multiple elements can have the same values.

*/

int main()
{
    multiset<int,greater<int>> m_set;
    m_set.insert(10);
    m_set.insert(20);
    m_set.insert(30);
    m_set.insert(40);

    multiset<int, greater<int>> :: iterator itr;
    for(itr = m_set.begin(); itr != m_set.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;
    return 0;
}