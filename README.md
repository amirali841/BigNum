BigNum Documentation

Introduction

The Bignum class is a C++ class that provides support for arbitrary-precision arithmetic for large integers. It allows you to perform arithmetic operations, such as addition, subtraction, and multiplication, on integers with a very large number of digits.



Class Definition

The Bignum class is defined in the "Bignum.h" header file. The class definition includes the following member functions and friend functions:



Member Functions

Bignum(string SNumber): Constructor that initializes a Bignum object with a string representation of a number.

Bignum(long long int z): Constructor that initializes a Bignum object with a long long integer.

~Bignum(): Destructor for the Bignum object.

void print(): Prints the value of the Bignum object.

int operator[](int): Overloaded subscript operator to access individual digits of the Bignum object.

Bignum &operator=(Bignum): Overloaded assignment operator to assign one Bignum object to another.

Bignum &operator=(long long int): Overloaded assignment operator to assign a long long integer to a Bignum object.

Bignum &operator=(string): Overloaded assignment operator to assign a string representation of a number to a Bignum object.

Bignum operator++(int): Overloaded post-increment operator.

Bignum operator--(int): Overloaded post-decrement operator.

Friend Functions

friend ostream &operator<<(ostream&, Bignum): Overloaded insertion operator for output stream to print the Bignum object.

friend istream &operator>>(istream&, Bignum&): Overloaded extraction operator for input stream to read a Bignum object.

friend Bignum operator-(Bignum , Bignum): Overloaded subtraction operator for two Bignum objects.

friend Bignum operator-(Bignum , long long int): Overloaded subtraction operator for a Bignum object and a long long integer.

friend int operator!=(Bignum , Bignum): Overloaded inequality operator for two Bignum objects.

friend int operator==(Bignum , Bignum): Overloaded equality operator for two Bignum objects.

friend int operator!=(Bignum , long long int): Overloaded inequality operator for a Bignum object and a long long integer.

friend int operator==(Bignum , long long int): Overloaded equality operator for a Bignum object and a long long integer.

friend int operator<=(Bignum , Bignum): Overloaded less than or equal to operator for two Bignum objects.

friend int operator>=(Bignum , Bignum): Overloaded greater than or equal to operator for two Bignum objects.

friend int operator>(Bignum , Bignum): Overloaded greater than operator for two Bignum objects.

friend int operator<(Bignum , Bignum): Overloaded less than operator for two Bignum objects.

friend Bignum operator*(Bignum , Bignum): Overloaded multiplication operator for two Bignum objects.

friend Bignum operator*(Bignum , long long int): Overloaded multiplication operator for a Bignum object and a long long integer.

friend Bignum operator+(Bignum , Bignum): Overloaded addition operator for two Bignum objects.

friend Bignum operator+(Bignum , long long int): Overloaded addition operator for a Bignum object and a long long integer.

friend Bignum operator+=(Bignum , Bignum): Overloaded compound addition operator for two Bignum objects.

friend Bignum operator-=(Bignum , Bignum): Overloaded compound subtraction operator for two Bignum objects.

friend Bignum operator*=(Bignum , Bignum): Overloaded compound multiplication operator for two Bignum objects.

friend Bignum operator+=(Bignum , long long int): Overloaded compound addition operator for a Bignum object and a long long integer.

friend Bignum operator+=(Bignum , long long int): Overloaded compound addition operator for a Bignum object and a long long integer.

friend Bignum operator+=(Bignum , long long int): Overloaded compound addition operator for a Bignum object and a long long integer.

Member Variables

The Bignum class also includes the following member variables:



unsigned int size: The number of digits in the Bignum object.

string SNum: The string representation of the Bignum object.

int plus_negetive: Indicates whether the Bignum object is positive (1) or negative (0).

Usage Example



#include <iostream>

#include "Bignum.h"

using namespace std;



int main()

{

    Bignum a1("-78568456848654665463203");
    
    Bignum a2(5946878203);
    
    Bignum a3(-2946);
    
    Bignum a4(+7784);
    
    Bignum a5("+3454111222554578203");
    
    Bignum a6("-19465124512887989741078203");
    
    Bignum a7 = 1282503;
    
    Bignum a8 = -4449203;



    cout << "a1 is:" << a1 << endl;
    
    cout << "a2 is:" << a2 << endl;
    
    cout << "a3 is:" << a3 << endl;
    
    cout << "a4 is:" << a4 << endl;
    
    cout << "a5 is:" << a5 << endl;
    
    cout << "a6 is:" << a6 << endl;
    
    cout << "a7 is:" &```html

#include 

#include "Bignum.h"

using namespace std;



int main()

{

    Bignum a1("-78568456848654665463203");
    
    Bignum a2(5946878203);
    
    Bignum a3(-2946);
    
    Bignum a4(+7784);
    
    Bignum a5("+3454111222554578203");
    
    Bignum a6("-19465124512887989741078203");
    
    Bignum a7 = 1282503;
    
    Bignum a8 = -4449203;



    cout << "a1 is: " << a1 << endl;
    
    cout << "a2 is: " << a2 << endl;
    
    cout << "a3 is: " << a3 << endl;
    
    cout << "a4 is: " << a4 << endl;
    
    cout << "a5 is: " << a5 << endl;
    
    cout << "a6 is: " << a6 << endl;
    
    cout << "a7 is: " << a7 << endl;
    
    cout << "a8 is: " << a8 << endl;



    cout << "a1 + a2 + a3 is: " << a1 + a2 + a3 << endl;
    
    cout << "a1 - a5 is: " << a1 - a5 << endl;
    
    
    cout << "a1 - a7 + a6 is: " << a1 - a7 + a6 << endl;
    
    cout << "a1 - 273095 is: " << a1 - 273095 << endl;
    
    cout << "a4 + 78465 is: " << a4 + 78465 << endl;



    cout << "a5[10] is: " << a5[10] << endl;



    Bignum enter(0);
    
    cin >> enter;
    
    cout << enter << endl;



    return 0;

}
