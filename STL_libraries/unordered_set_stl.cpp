#include<iostream>
#include<unordered_set>
#include<string> 
#include<iterator>
using namespace std;

/*
    UNORDERED_SET : An unordered_set is implemented using a hash table where keys are hashed into indices of a hash table so that the insertion is always randomized.
    The unordered_set can contain key of any type – predefined or user-defined data structure.

*/

int main()
{
    unordered_set <string> hash;
    hash.insert("cpp");
    hash.insert("hello");
    hash.insert("world");
    hash.insert("hash");
    hash.insert("map");

    unordered_set<string> :: iterator itr;
    for(itr = hash.begin(); itr != hash.end(); itr++)
    {
        cout << *itr << ' ';
    } 
    cout << '\n';

    // find the key
    if(hash.find("map") == hash.end())
    {
        cout << "The key has been not found" << endl;
    }
    else cout << "The key been found" << endl;
    return 0;
}

****************************************************************************************************************************


// FIND THE DUPLICATES IN THE UNORDERED SET AND PRINT THEM -> ARRAY
void print_duplicates(int array[], int n)
{
    unordered_set<int> hash_set;
    unordered_set<int> duplicates;

    // loop through the array
    for(int i=0; i<n; i++)
    {
        // find if the elements already exists in hash_set
        if(hash_set.find(array[i]) == hash_set.end())
        {
            // if not add them in hash_set
            hash_set.insert(array[i]);
        }
        else
        {
            // if they exits already then add them in duplicates
            duplicates.insert(array[i]);
        }
    }
    unordered_set<int> :: iterator itr;
    for(itr = duplicates.begin(); itr != duplicates.end(); itr++)
    {
        cout << *itr << " "; 
    }

}



int main()
{
    int arr[] = {1, 5, 2, 1, 4, 3, 1, 7, 2, 8, 9, 5};
    int n = sizeof(arr) / sizeof(int);
    print_duplicates(arr,n);
    return 0;
}
