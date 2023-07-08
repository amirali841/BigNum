#ifndef BIGNUM_H_INCLUDED
#define BIGNUM_H_INCLUDED


#include <iostream>
using namespace std;

class Bignum
{
    friend ostream &operator<<(ostream&, Bignum);
    friend istream &operator>>(istream&, Bignum&);
    friend Bignum operator-(Bignum , Bignum);
    friend Bignum operator-(Bignum , long long int);
    friend int operator!=(Bignum , Bignum);
    friend int operator==(Bignum , Bignum);
    friend int operator!=(Bignum , long long int);
    friend int operator==(Bignum , long long int);
    friend int operator<=(Bignum , Bignum);
    friend int operator>=(Bignum , Bignum);
    friend int operator>(Bignum , Bignum);
    friend int operator<(Bignum , Bignum);
    friend Bignum operator*(Bignum , Bignum);
    friend Bignum operator*(Bignum , long long int);
    friend Bignum operator+(Bignum , Bignum);
    friend Bignum operator+(Bignum , long long int);
    friend Bignum operator+=(Bignum , Bignum);
    friend Bignum operator-=(Bignum , Bignum);
    friend Bignum operator*=(Bignum , Bignum);
    friend Bignum operator+=(Bignum , long long int);
    friend Bignum operator+=(Bignum , long long int);
    friend Bignum operator+=(Bignum , long long int);
public:
    int operator[](int);
    Bignum &operator=(Bignum);
    Bignum &operator=(long long int);
    Bignum &operator=(string);
    Bignum operator++(int);
    Bignum operator--(int);
    Bignum(string = "0");
    Bignum(long long int = 0);
    ~Bignum();
    unsigned int size;
    void print();
    string SNum = "";
    int plus_negetive;// 1 is plus and 0 is negetive


};


#endif // BIGNUM_H_INCLUDED
