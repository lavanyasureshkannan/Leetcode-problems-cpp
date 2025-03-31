#include <iostream>
using namespace std;


/*
Static memory (also called the data segment or global section) is a region of memory where:

Global variables

Static variables

Static class members

are stored — and they exist for the entire life of the program.


+--------------------+
| Code Section       | ← your compiled instructions
+--------------------+
| Static / Global    | ← ⚡ static memory
| (global/static vars)|   stays alive until program ends
+--------------------+
| Heap (dynamic)     | ← 🧠 memory from malloc/new
+--------------------+
| Stack              | ← 📚 local variables, function calls
+--------------------+
*/

int a = 10; //global variable
static int b = 4; // static variable

void foo()
{
    static int c; // static local variable
}

class base
{
    public:
    void foo()
    {
        static int d; // static class variable
    }
}

int main()
{
    return 0;
}
