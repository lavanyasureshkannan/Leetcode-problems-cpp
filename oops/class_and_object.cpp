#include<iostream>
using namespace std;


//CLASS AND OBJECT

// Class
class group
{
    public:
    string name;
    int id;

    void display()
    {
        cout << "The name of the student is: " << name << endl;
        cout << "The id of the student is: "<< id << endl; 
    }   
};

int main()
{
    // object
    group G1;

    // declare the variables inside G1
    G1.name = "lavanya";
    G1.id = 171;

    // call the display function
    G1.display();
    
    return 0; 
}

// SIZE OF THE CLASS -> 1 BYTE
// SIZE OF THE OBJECT -> is equal to the sum of size of all the data members of the class.


