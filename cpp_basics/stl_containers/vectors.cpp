#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    vectors => Is is a dynamic array that stores the collection of data.
*/

void print_vector(vector<int>& v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << endl;
    }
}

int main()
{
    vector<int> v1;
    // 1. ADD elements to v
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(20);
    v1.push_back(40);
    v1.push_back(50);

    vector<int> v2(5,9);
    //print_vector(v1);
    //print_vector(v2);
    
    // 2. ACCESS elements from v
    //cout << v1[2] << endl;
    //cout << v1.at(2) << endl;

    // 3. DELETE elements from v
    v1.pop_back(); // deletes/pops the last element
    v1.erase(find(v1.begin(), v1.end(), 20)); // this deletes the first find 20
    //print_vector(v1);

    // 4. Reverse elements from v
    reverse(v1.begin(), v1.end());
    print_vector(v1);
    return 0;
}