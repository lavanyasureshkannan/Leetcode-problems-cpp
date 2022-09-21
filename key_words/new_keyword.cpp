#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

// new -> The new operator is an operator which denotes a request for memory allocation on the Heap. If sufficient memory is available, new operator initializes the memory and returns the address of the newly allocated and initialized memory to the pointer variable. 

class vehicle
{
    private:
    int number;
    string type;

    public:
    vehicle(int n, string m)
    {
        this->number = n;
        this->type = m;
    }
    void display()
    {
        cout << number << endl;
        cout << type << endl;
    }

};


// operator new keyword => Operator new is a function that allocates raw memory and conceptually a bit similar to malloc().
// It is the mechanism of overriding the default heap allocation logic.
// It doesn’t initializes the memory i.e constructor is not called. However, after our overloaded new returns, the compiler then automatically calls the constructor also as applicable.
// It’s also possible to overload operator new either globally, or for a specific class

class student
{
    int age;
    string name;

    public:
    student(int a, string s)
    {
        cout << "constructor is invoked" << endl;
        this->age = a;
        this->name = s;
    }
    void display()
    {
        cout << name << endl;
        cout << age << endl;
    }

    void *operator new(size_t size)
    {
        cout << "new operator is overloaded " << endl;
        void *ptr = malloc(size);
        return ptr;
    }

    void operator delete(void *ptr)
    {
        cout << "deleting the operator overloader" << endl;
        free(ptr);
    }
};

int main()
{
    // you cannot create an object normally like "vehicle car" because no default constructor exists
    // vehicle* car = new vehicle(20, "honda");
    // car->display();

    student * s1 = new student(22, "lav");
    s1->display();
    delete s1;
    return 0;
}