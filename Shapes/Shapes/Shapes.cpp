#include <iostream>
#include <iomanip>

//Bijan Amirzadehasl 06/20/2021
using namespace std;
// create the Rectangle Class
class Rectangle
{
protected:
    //two protected data members
    int sideA;
    int sideB;
public:
    // variable declaration from sample file
    Rectangle(int, int);
    void setSideA(int);
    void setSideB(int);
    int getSideA();
    int getSideB();
    int computePerimeter();
    int computeArea();
    void operator++();
    void operator--();
    bool operator==(Rectangle r1);
};
// Constructor that uses a set to make sure user can't pass in a value of 0 or below
Rectangle::Rectangle(int sideA, int sideB)
{
    setSideA(sideA);
    setSideB(sideB);

}
// Getters
int Rectangle::getSideA()
{
    return sideA;
}
int Rectangle::getSideB()
{
    return sideB;
}
//Setters that defaults a user to a positive value
void Rectangle::setSideA(int sideA)
{
    if (sideA > 0)
        this->sideA = sideA;
    else
        this->sideA = 1;
}
void Rectangle::setSideB(int sideB)
{
    if (sideB > 0)
        this->sideB = sideB;
    else
        this->sideB = 1;
}

// Function to compute the perimter 
int Rectangle::computePerimeter()
{
    return 2 * (sideA + sideB);
}
// Function to compute area
int Rectangle::computeArea()
{
    return sideA * sideB;
}
//overload the increment operator
void Rectangle::operator ++()
{
    ++sideA;
    ++sideB;
}
//overload the decrement operator
void Rectangle::operator --()
{
    --sideA;
    --sideB;
}
//overload the equality operator to test two rectangle objects for equality
bool Rectangle::operator==(Rectangle r1)
{
    if (this->sideA == r1.sideA && this->sideB == r1.sideB)
        return true;
    else
        return false;
}
//Coding the square class to inherit from Rectangle class
class Square : public Rectangle
{
public:
    Square(int);
    void setSideA(int);
    void setSideB(int);
};
Square::Square(int side)
    : Rectangle(side, side)
{
}
void Square::setSideA(int side)
{
    setSideA(side);
}
void Square::setSideB(int side)
{
    setSideB(side);
}
void displayData(Rectangle shape);
//Main method to test class hierachy 
int main()
{
    //declare variables 
    int side;
    int sideA;
    int sideB;
    // prompt the user for lenght of square side
    cout << "Testing the Square Class" << endl;
    cout << "Enter length of the side:";
    cin >> side;
    cout << endl;
    // create an instance of the square class
    Square s1(side);
    //call the displayData function passing it the object
    displayData(s1);
    cout << endl;
    //calling the increment function
    cout << "After calling the increment operator" << endl;
    s1.operator++();
    cout << endl;
    displayData(s1);
    cout << endl;
    //Performing the same tests from above but using the rectangle class object
    cout << "Testing the Rectangle Class" << endl;
    cout << "Enter length of the side A: ";
    cin >> sideA;
    cout << "Enter length of the side B: ";
    cin >> sideB;
    cout << endl;
    Rectangle r1(sideA, sideB);
    displayData(r1);
    cout << endl;
    //call the decrement operator
    cout << "After calling the decrement operator" << endl;
    r1.operator--();
    cout << endl;
    displayData(r1);

    if
        (r1.operator==(r1) == true && s1 == r1) {
        cout << "\nThe objects are the same size.";
    }
    else {
       cout << "\nThe objects are of unequal sides.";
    }

   

    return 0;
}

//function to automate data display for equations
void displayData(Rectangle shape)
{
    cout << "\nThe length of side A is " << shape.getSideA() << endl;
    cout << "The length of side B is " << shape.getSideB() << endl;
    cout << "The Perimeter is " << shape.computePerimeter() << endl;
    cout << "The Area is " << shape.computeArea() << endl;
}
