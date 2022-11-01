// CPP program to demonstrate multithreading
// using three different callables.
#include <iostream>
#include <thread>
using namespace std;

/*
To start a thread we simply need to create a new thread object and pass the executing code to be called (i.e, a callable object) into the constructor of the object.
Once the object is created a new thread is launched which will execute the code specified in callable.
A callable can be either of the three
A function pointer
A function object
A lambda expression
After defining callable, pass it to the constructor.
*/


// A dummy function
void foo(int Z)
{
	for (int i = 0; i < Z; i++) {
		cout << "Thread using function"
			" pointer as callable\n";
	}
}

// A callable object
class thread_obj {
public:
	void operator()(int x)
	{
		for (int i = 0; i < x; i++)
			cout << "Thread using function"
				" object as callable\n";
	}
};

int main()
{
	cout << "Threads 1 and 2 and 3 "
		"operating independently" << endl;

	// This thread is launched by using
	// function pointer as callable
	thread th1(foo, 3);

	// This thread is launched by using
	// function object as callable
	thread th2(thread_obj(), 3);

	// Define a Lambda Expression
	auto f = [](int x) {
		for (int i = 0; i < x; i++)
			cout << "Thread using lambda"
			" expression as callable\n";
	};

	// This thread is launched by using
	// lamda expression as callable
	thread th3(f, 3);

	// Wait for the threads to finish
	// Wait for thread t1 to finish
	th1.join();

	// Wait for thread t2 to finish
	th2.join();

	// Wait for thread t3 to finish
	th3.join();

	return 0;
}
