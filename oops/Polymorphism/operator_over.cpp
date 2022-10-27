#include<iostream>
#include<vector>
using namespace std;


struct Student
{
    string m_name;
    int m_age;

    Student(string name, int age)
    {
        m_name = name;
        m_age = age;
    }
};

// when you want to over load "<<", we create a new overloading function
// operator function:
        // operator symbol (datatype& param1_left, datatype& param2_right)


// void operator<<(ostream& COUT, Student& ss1)
// {
//     COUT << "Name: " << ss1.m_name << endl;
//     COUT << "Age: " << ss1.m_age << endl;
// } 

ostream& operator<<(ostream& COUT, Student& ss1)
{
    COUT << "Name: " << ss1.m_name << endl;
    COUT << "Age: " << ss1.m_age << endl;
    return COUT;

}

int main()
{
    Student s1 = Student("lavanya", 23);
    Student s2 = Student("manisha", 25);
    // cout << s1 << endl;
    // we can also use the operator function as normal function
    operator<<(cout, s1);

    return 0;
}
