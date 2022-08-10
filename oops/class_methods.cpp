#include<iostream>
using namespace std;


//METHODS -< CLASSSES
// inside and outside classes

// inside class -> defining a function inside the class

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

// outside class -> defining a function outside the class with the :: scopre resolution sign

class vehicle
{
    public:
    
    string name;
    int wheels;

    void display_out();
};

void vehicle :: display_out()
{
    cout << "display the name of the vehicle: " << name << endl;
    cout << "display the type of the vehicle: " << wheels << endl;
} 

class animal
{
    public:
    int type_of_legs(int max_legs);
};

int animal :: type_of_legs(int max_legs)
{
    cout << "the number of legs in the animals are: " << max_legs << endl;
    return max_legs;
}



int main()
{
    // object
    vehicle vehicle_1;

    // declare the variables inside G1
    vehicle_1.name = "car";
    vehicle_1.wheels = 4;

    // call the display function
    vehicle_1.display_out();



    
    animal dog;
    dog.type_of_legs(4); 
    
    return 0; 
}

