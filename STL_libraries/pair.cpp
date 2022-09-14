#include<iostream>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

/*
    PAIR in C++ -> Standard Template Library
    Pair is used to combine together two values that may be of different data types. 
    Pair provides a way to store two heterogeneous objects as a single unit. 
    It is basically used if we want to store tuples. 

    The syntax of the pair is,
    "pair <data type 1, data type 2> p" 
    The first element is referenced as ‘first’ and the second element as ‘second’ and the order is fixed (first, second).
*/

int main()
{
    // Initialising pair 

    // APPROACH 1

    pair<int,char> p1;
    p1.first = 10;
    p1.second = 'a';
    cout << p1.first << " " << p1.second << endl;

    // APPROACH 2
    pair<int,char> p2(20,'b');
    cout << p2.first << " " << p2.second << endl;

    // APPROACH 3
    pair<int, char> p3;
    p3 = make_pair(30, 'c');
    cout << p3.first << " " << p3.second << endl;


    // swap pairs
    pair<int,char> s_pair1 = make_pair(1,'a');
    pair<int,char> s_pair2 = make_pair(2,'b');
    // before swapping
    cout << "In pair one: "<< s_pair1.first << " " << s_pair1.second << endl;
    cout << "In pair two: "<< s_pair2.first << " " << s_pair2.second << endl;
    swap(s_pair1,s_pair2);
    // after swapping
    cout << "In pair one: "<< s_pair1.first << " " << s_pair1.second << endl;
    cout << "In pair two: "<< s_pair2.first << " " << s_pair2.second << endl;
    
    // pair of pairs by using the function called tie
    pair<int, pair<int,char>> pp = {50,{40,'P'}};
    int x;
    x = pp.first;

    int y;
    char z;
    tie(y,z) = pp.second; 
    cout << x << " " << y << " " << z << endl;
    return 0;
}