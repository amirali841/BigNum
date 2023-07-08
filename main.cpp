#include <iostream>
#include "Bignum.h"
using namespace std;
int main()
{
    Bignum a1("78568456848654665463203");
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
    cout << "a7 is:" << a7 << endl;
    cout << "a8 is:" << a8 << endl;
    cout << "a1 + a2 + a3 is:" << a1 + a2 + a3 << endl;
    cout << "a1 - a5 is:" << a1 - a5 << endl;
    cout << "a1 - a7 + a6 is:" << a1 - a7 + a6 << endl;
    cout << "a1 - 273095 is:" << a1 - 273095 << endl;
    cout << "a4 + 78465 is:" << a4 + 78465 << endl;
//    cout << "a2 * a3 is:" << a2 * a3 << endl;
    cout << "a5[10] is: " << a5[10] << endl;


    a1 += a3;
    a5 -= a2;
    cout << "a5 is:" << a5 << endl;
    cout << "a1 is:" << a1 << endl;

    if(a2 > a1)
        cout << "a2 > a1" << endl;
    else
        cout << "a2 < a1" << endl;

    if(a2 < a1)
        cout << "a2 < a1" << endl;
    else
        cout << "a2 > a1" << endl;

    if(a2 == a1)
        cout << "a2 == a1" << endl;
    else
        cout << "a2 != a1" << endl;

    if(a2 <= a1)
        cout << "a2 <= a1" << endl;
    else
        cout << "a2 > a1" << endl;

    if(a2 >= a1)
        cout << "a2 >= a1" << endl;
    else
        cout << "a2 < a1" << endl;

    if(a1 == a2)
        cout << "a1 == a2" << endl;
    else
        cout << "a1 != a2" << endl;


    if(a1 != a2)
        cout << "a1 != a2" << endl;
    else
        cout << "a1 == a2" << endl;

    cout << "print for a1 : ";
    a1.print();
    cout << endl;
    cout << "print for a2 : ";
    a2.print();
    cout << endl;
    cout << "print for a3 : ";
    a3.print();
    cout << endl;
    cout << "print for a4 : ";
    a4.print();
    cout << endl;
    cout << "print for a5 : ";
    a5.print();
    cout << endl;
    cout << "print for a6 : ";
    a6.print();
    cout << endl;
    cout << "print for a7 : ";
    a7.print();
    cout << endl;
    cout << "print for a8 : ";
    a8.print();
    cout << endl;

    Bignum enter(0);
    cin >> enter;
    cout << enter << endl;
   return 0;
}
