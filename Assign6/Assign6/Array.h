// Fig. 10.10: Array.h
// Array class definition with overloaded operators.
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <iomanip>
using namespace std;

template <class numbers>
class Array
{
	// friend std::ostream &operator<<( std::ostream &, const Array & );
	 // overloaded output operator for class Array 
	friend std::ostream& operator<<(std::ostream& output, const Array<numbers> &a)
	{
		// output private ptr-based array 
		for (size_t i = 0; i < a.size; ++i)
		{
			output << setw(12) << a.ptr[i];

			if ((i + 1) % 4 == 0) // 4 numbers per row of output
				output << endl;
		} // end for

		if (a.size % 4 != 0) // end last line of output
			output << endl;

		return output; // enables cout << x << y;
	} // end function operator<<

//   friend std::istream &operator>>( std::istream &, Array & );
   // overloaded input operator for class Array;
	// inputs values for entire Array
	friend std::istream& operator>>(std::istream& input, Array<numbers> &a)
	{
		for (size_t i = 0; i < a.size; ++i)
			input >> a.ptr[i];

		return input; // enables cin >> x >> y;
	} // end function 


public:
	explicit Array(int arraySize = 3)
		: size(arraySize > 0 ? arraySize :
			throw invalid_argument("Array size must be greater than 0")),
		ptr(new numbers[size])
	{
		for (size_t i = 0; i < size; ++i)

			ptr[i] = 0; // set pointer-based array element
	} // end Array default constructor

//   ~Array(); // destructor
	~Array()
	{
		delete[] ptr; // release pointer-based array space
	} // end destructor

//   size_t getSize() const; // return size
   // return number of elements of Array
	size_t getSize() const
	{
		return size; // number of elements in Array
	} // end function getSize

 //  const Array &operator=( const Array & ); // assignment operator
   // const return avoids: ( a1 = a2 ) = a3
	const Array<numbers> &operator=(const Array& right)
	{
		if (&right != this) // avoid self-assignment
		{
			// for Arrays of different sizes, deallocate original
			// left-side Array, then allocate new left-side Array
			if (size != right.size)
			{
				delete[] ptr; // release space
				size = right.size; // resize this object
				ptr = new numbers[size]; // create space for Array copy
			} // end inner if

			for (size_t i = 0; i < size; ++i)
				ptr[i] = right.ptr[i]; // copy array into object
		} // end outer if

		return *this; // enables x = y = z, for example
	} // end function operator=


 //  bool operator==( const Array & ) const; // equality operator   
   // determine if two Arrays are equal and
	// return true, otherwise return false
	bool operator==(const Array<numbers> &right) const
	{
		if (size != right.size)
			return false; // arrays of different number of elements

		for (size_t i = 0; i < size; ++i)
			if (ptr[i] != right.ptr[i])
				return false; // Array contents are not equal

		return true; // Arrays are equal
	} // end function operator==

   // subscript operator for const objects returns rvalue
//   int operator[]( int ) const;  
   // overloaded subscript operator for const Arrays
	// const reference return creates an rvalue
	numbers operator[](int subscript) const
	{
		// check for subscript out-of-range error
		if (subscript < 0 || subscript >= size)
			throw out_of_range("Subscript out of range");

		return ptr[subscript]; // returns copy of this element
	} // end function operator[]

private:
	size_t size; // pointer-based array size
	numbers *ptr; // pointer to first element of pointer-based array
}; // end class Array

#endif
