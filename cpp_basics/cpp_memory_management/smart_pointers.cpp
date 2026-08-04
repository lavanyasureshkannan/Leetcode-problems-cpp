#include <iostream>
#include <memory>
using namespace std;

int main()
{
    /////////////////////// debugging //////////////////////////////

    // SCENARIO 1

    // int* p;
    // {
    //     int x = 10;
    //     p = &x;
    // }
    // std::cout << *p << std::endl; this case might print 10 but p becomes dangling pointer
    // because the lifetime of the variable x ends inside the scope. 
    // Therefore we are going to use smart pointer
    
    // FIX 
    // std::unique_ptr<int> p = std::make_unique<int>(10);
    
    /*******************************************************************************************/

    // SCENARIO 2

    // int* p = new int (10);
    // int* q = p;
    // delete p;
    // cout << *q << endl; // this throws random garbage value.

    // FIX
    // unique_ptr<int> p = make_unique<int> (10);
    // unique_ptr<int> q = move(p);

    // //cout << *p << endl;
    // cout << *q << endl;
    
    /*******************************************************************************************/
    // SCENARIO 3
    // int* p = new int(10);
    // int x = 10;
    // int* ptr = &x;
    
    // int **q = &p;
    //cout << **q << endl;

    /*******************************************************************************************/
    // SCENARIO 4
    // unique_ptr<int> m = make_unique<int> (13);
    // cout << m.get() << endl;
    // unique_ptr<int> n = move(m);
    // cout << n.get() << endl; // .get keyword prints the memory address
    
    // m.reset();
    // cout << m.get() << endl;
    
    // m.reset(new int (25));
    // cout << m.get() << endl;

    /*******************************************************************************************/
    // SCENARIO 5
    // unique_ptr<int> m = make_unique<int> (12); 
    // cout << m.get() << endl;
    // {
    //     unique_ptr<int> n = move(m);
    //     cout << m.get() << endl;
    //     cout << n.get() << endl;
    // }
    // cout << m.get() << endl; // here m still prints 0 because once the memory is moved it wont magically come back.
    // // now m is waiting for us to use reset and bring back alive
    // m.reset(new int(5)); 
    // cout << *m << endl;
    // cout << m.get() << endl;
    return 0;
}