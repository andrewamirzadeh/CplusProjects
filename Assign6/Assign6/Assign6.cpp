//Name: 
//Date: 
// Assignment #6 - client application to test the Array class
#include <iostream>
#include <stdexcept>
#include <typeinfo>
#include "Array.h"
using namespace std; 

template <class numbers>
void numFunc(Array <numbers> &integers1, Array <numbers> &integers2)
{
    // print integers1 size and contents
    cout << "Size of first Array object is "
        << integers1.getSize()
        << "\nArray after initialization:\n" << integers1;

    // print integers2 size and contents
    cout << "\nSize of second Array object is "
        << integers2.getSize()
        << "\nArray after initialization:\n" << integers2;

    // input and print integers1 and integers2
    cout << "\nEnter " << (integers1.getSize() + integers2.getSize()) << " " << typeid(numbers).name() << " values:" << endl;
    cin >> integers1 >> integers2;

    cout << "\nAfter input, the Arrays contain:\n"
        << "First Array object:\n" << integers1
        << "Second Array object:\n" << integers2;

    // use overloaded assignment (=) operator
    cout << "\nAssigning second Array object to the first Array object:" << endl;
    integers1 = integers2; // note target Array is smaller

    cout << "First Array object:\n" << integers1
        << "Second Array object:\n" << integers2;

    // use overloaded equality (==) operator
    cout << "\nEvaluating for equality" << endl;

    if (integers1 == integers2)
        cout << "The Array objects are equal" << endl;
    else
        cout << "The Array objects are not equal" << endl;

    // use overloaded subscript operator to create rvalue
    cout << "\nValue of first element in first Array object is " << integers1[0] << endl;
}
int main()
{
    Array<int> integers1(2); // 2-element Array
    Array<int> integers2; // 3-element Array by default

    numFunc(integers1, integers2);
 
    Array<double> double1(2);
    Array<double> double2;

    numFunc(double1, double2);

    Array<char> char1(2);
    Array<char> char2;

    numFunc(char1, char2);


} // end main