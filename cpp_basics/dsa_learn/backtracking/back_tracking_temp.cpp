#include <iostream>
using namespace std;

/*
    BACKTRACKING USING RECURRSION
    1. Try -> Explore -> Undo -> Try something else
    2. Backtracking = recursion + undo
*/

// template
void backtrack(params)
{
    if(basecase)
    {
        save_answer();
        return;
    }
    for(each_choice)
    {
        make_choice();
        backtrack();
        undo();
    }
}

/*
    Things to remember
    1. i => For index, use i when you want to reuse the vals inside (combination sums). 
    2. i+1 => Use i+1 when you donot want to use the same index again (subsets, combinations, combination_sums2).
    3. index+1 => if you want fixed position for binary yes/no situations use index+1 (permutations)
*/