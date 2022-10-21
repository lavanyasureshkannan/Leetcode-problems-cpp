#include<iostream>
#include<unordered_map>
/*
    TREENODE
    1. Tree is use to store the strings
    2. Each node will represent the child node
    3. Two ways to represent the data struct
            -> using arrays
            -> using maps
*/

#define N 26

// array
struct Treenode
{
    TreeNode* children[N];
};

//unordered_map
struct TreeNode
{
    // key : char, value : corresponding child node
    std::unordered_map<char, TreeNode*> children;
};

// array solution
class Trie
{
    // 26 pointers 
    Trie* children[N];
    bool isEndWord;

    public:
    Trie()
    {
        isEndWord = false;
        // intially all the children is going to have a null ptr
        for(int i=0; i<N; i++)
        {
            children[i] = nullptr;
        }
    }

    void insert(std::string words)
    {
        Trie* curr = this;
        for(char c : words)
        {
            // see if it is empty or not
            if(!(curr->children[c - 'a']))
            {
                // if not create a new trie
                curr->children[c - 'a'] = new Trie;
            }
            curr = curr->children[c - 'a'];
        }
        // if the word is reached
        curr->isEndWord = true;
    }

    bool search(std::string words)
    {
        Trie* curr = this;
        for(char c : words)
        {
            // see if it is empty or not
            if(!(curr->children[c - 'a'])) return false;
        }
        if(curr->isEndWord) return true;
        return false;
    }

    // returning the word in the tree that starts with the prefix
    bool startsWith(std::string prefix)
    {
        Trie* curr = this;
        for(char c : prefix)
        {
            // see if it is empty or not
            if(!(curr->children[c - 'a'])) return false;
        }
        return true;       
    }

};

// TC: O(N)
// SC: O(N)