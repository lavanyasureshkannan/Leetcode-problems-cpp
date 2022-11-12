/*
    Vtable : It is a table that contains the memory addresses of all virtual functions of a class in the order in which they are declared in a class. 
    This table is used to resolve function calls in dynamic/late binding manner. 
    Every class that has virtual function will get its own Vtable.

    VPTR : After creating Vtable address of that table gets stored inside a pointer i.e. VPTR (Virtual Pointer). 
    When you create an object of a class which contains virtual function then a hidden pointer gets created automatically in that object by the compiler. 
    That pointer points to a virtual table of that particular class.
*/