#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// C++ 11 introduced lambda expressions to allow inline functions which can be used for short snippets of code that are not going to be reused and therefore do not require a name.
// [capture cluase] (parameters) {function definition}

int main()
{
    // you can use the capture clause to access the values inside the main function
    int a = 3;
    vector<int>nums = {1,2,3,4,6};
    for_each(nums.begin(), nums.end(), [a](int x){
        if(x%a == 0)
        {
            cout << "divisible" << endl;
        }
        else
        {
            cout << "not divisible" << endl;
        }
    }
    );
    return 0;
}