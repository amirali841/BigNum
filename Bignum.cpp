#include "Bignum.h"
#include <iostream>
#include <string>
using namespace std;

Bignum::Bignum(string SNumber)
{
    if(SNumber[0] >= '0' && SNumber[0] <= '9')
    {
        size = SNumber.length();
        plus_negetive = 1;
    }
    if(SNumber[0] == '+' || SNumber[0] == '-')
        size = (SNumber.length() - 1);
    if(SNumber[0] == '+')
        plus_negetive = 1;
    if(SNumber[0] == '-')
        plus_negetive = 0;
    if(SNumber[0] == '+' || SNumber[0] == '-')
        for(int i = 1 ; i < size + 1 ; i++)
            SNum += SNumber[i];
    if(SNumber[0] >= '0' && SNumber[0] <= '9')
        SNum = SNumber;
}

Bignum::Bignum(long long int z)
{
    string temp = to_string(z);
    if(z > 0)
    {
        SNum = temp;
        size = temp.length();
        plus_negetive = 1;
    }
    if(z < 0)
    {
        for(int i = 1 ; i < temp.length() ; i++)
            SNum += temp[i];
        size = temp.length() - 1;
        plus_negetive = 0;
    }
}


Bignum::~Bignum()
{}
void Bignum::print()
{
    int m;
    if(SNum[0] == '0')
    {
    for(int i = 0 ; i < size ; i++)
        if(SNum[i] > '0' && SNum[i] <= '9')
        {
            m = i;
            break;
        }
    for(int i = m , j = 0; i < size + m ; i++ , j++)
        SNum[j] = SNum[i];
    size = size - m;
    }
    if(plus_negetive == 1)
        cout << '+';
    if(plus_negetive == 0)
        cout << '-';
    if(size > 3)
    {
        for(int i = 0 ; i < size % 3 ; i++)
        {
            cout << SNum[i];
            m = 1;
        }
        if(m > 0)
            cout << ",";
        for(int i = (size % 3) ; i < size ; i++)
        {
            if(((i - (size % 3)) % 3) == 0 && i != (size % 3))
                cout << ",";
            cout << SNum[i];
        }
    }
    else
    {
        cout << SNum << endl;
    }
}

Bignum operator+(Bignum num, long long int z)
{
    Bignum num1(0);
    int m = 0;
    num1.SNum = to_string(z);
    while(z != 0)
    {
        m++;
        z /= 10;
    }
    num1.size = m;
    if(z > 0)
        num1.plus_negetive = 1;
    if(z < 0)
        num1.plus_negetive = 0;
    return (num1 + num);
}


Bignum operator+(Bignum num1 , Bignum num2)
{
    if((num1.plus_negetive == 1 && num2.plus_negetive == 0))
    {
        Bignum answer(0);
        num2.plus_negetive = 1;
        answer = (num1 - num2);
        num2.plus_negetive = 0;
        return answer;
    }
    if((num1.plus_negetive == 0 && num2.plus_negetive == 1))
    {
        Bignum answer(0);
        num1.plus_negetive = 1;
        answer = (num2 - num1);
        num1.plus_negetive = 0;
        return answer;
    }
        Bignum numm(0);
        unsigned int max_size;
        string ans;
         if(num1.size >= num2.size)
            max_size = num1.size;
        else
            max_size = num2.size;

       if(num1.size > num2.size)
       {
            for(int i = 0 ; i < num1.size - num2.size ; i++)
                num2.SNum = '0' + num2.SNum;
            num2.size = max_size;
       }
       if(num2.size > num1.size)
       {
           for(int i = 0 ; i < num2.size - num1.size ; i++)
                num1.SNum = '0' + num1.SNum;
            num1.size = max_size;
       }
        for(int i = 0 ; i < max_size + 1 ; i++)
            ans = '0' + ans;
        for(int i = max_size - 1 ; i >= 0 ; i--)
        {
            if(((num1.SNum[i] - '0') + (num2.SNum[i] - '0')) < 10)
            {
                ans[i+1] += (num1.SNum[i] + num2.SNum[i] - '0' - '0');
                if(ans[i+1] >= ('0' + 10))
                    {
                        ans[i+1] = '0';
                        ans[i] += 1;
                    }
        }
        if(((num1.SNum[i] - '0') + (num2.SNum[i] - '0')) >= 10)
        {
            ans[i+1] += ((num1.SNum[i] - '0') + (num2.SNum[i] - '0') - 10);
            ans[i] += 1;
        }
    }

    numm.SNum = ans;
    numm.size = ans.length();
    numm.plus_negetive = 1;
    if((num1.plus_negetive == 0 && num2.plus_negetive == 0))
    {
        numm.plus_negetive = 0;
    }

    return numm;
}

Bignum operator-(Bignum num1 , Bignum num2)
{
    if(num1.plus_negetive == 1 && num2.plus_negetive == 0)
    {
        num2.plus_negetive = 1;
        Bignum answer(0);
        answer = (num1 + num2);
        num2.plus_negetive = 0;
        return answer;
    }
    if(num1.plus_negetive == 0 && num2.plus_negetive == 1)
    {
        Bignum answer(0);
        answer = (num1 + num2);
        answer.plus_negetive = 0;
        return answer;
    }
    if((num1.plus_negetive == 0 && num2.plus_negetive == 0))
    {
        Bignum temp(0);
        temp = num1;
        num1 = num2;
        num2 = temp;
    }
    if(num1 < num2)
    {
        Bignum answer(0);
        answer = (num2 - num1);
        answer.plus_negetive = 0;
        return answer;
    }
    if(num1 == num2)
    {
        Bignum answer(0);
        answer = 0;
        return answer;
    }
        unsigned int max_size;
        string ans;
        if(num1.size >= num2.size)
            max_size = num1.size;
        else
            max_size = num2.size;

        if(num1.size > num2.size)
       {
            for(int i = 0 ; i < num1.size - num2.size ; i++)
                num2.SNum = '0' + num2.SNum;
            num2.size = max_size;
       }

       if(num2.size > num1.size)
       {
           for(int i = 0 ; i < num2.size - num1.size ; i++)
                num1.SNum = '0' + num1.SNum;
            num1.size = max_size;
       }


        for(int i = 0 ; i < max_size  ; i++)
            ans = '0' + ans;
        for(int i = max_size - 1 ; i >= 0 ; i--)
        {
            if(((num1.SNum[i] - '0') - (num2.SNum[i] - '0')) < 0)
            {
                ans[i] += (((num1.SNum[i] - '0') - (num2.SNum[i] - '0')) + 10);
                ans[i-1] -= 1;
            }
            if(((num1.SNum[i] - '0') - (num2.SNum[i] - '0')) > 0)
            {
                ans[i] += ((num1.SNum[i] - '0') - (num2.SNum[i] - '0'));
            }
        }

        Bignum num(0);
        num.SNum = ans;
        num.size = ans.length();
        num.plus_negetive = 1;
        return num;
}

Bignum operator*(Bignum num1 , Bignum num2)
{
    unsigned int max_size;
    Bignum ans(0);
    Bignum temp(0);
    char c;
    if(num1.size >= num2.size)
        max_size = num1.size;
    else
        max_size = num2.size;

    if(num1.size > num2.size)
   {
        for(int i = 0 ; i < num1.size - num2.size ; i++)
            num2.SNum = '0' + num2.SNum;
        num2.size = max_size;
   }

   if(num2.size > num1.size)
   {
       for(int i = 0 ; i < num2.size - num1.size ; i++)
            num1.SNum = '0' + num1.SNum;
        num1.size = max_size;
   }

    for(int i = 0 ; i < max_size * 2 ; i++)
        ans.SNum = '0' + ans.SNum;

    for(int i = 0 ; i < max_size * 2 ; i++)
        temp.SNum = '0' + temp.SNum;

   for(int i = max_size - 1  , f = 0 ; i >= 0 ; i-- , f++)
   {
       c = num2.SNum[i];
       for(int j = max_size - 1 , m = (2 * max_size) - 1 ; j >= 0 ; j-- , m--)
       {
           if(((c - '0') * (num1.SNum[j] - '0')) < 10)
           {
              ans.SNum[m] += ((c - '0') * (num1.SNum[j] - '0'));
              if(ans.SNum[m] > '0' + 10)
              {
                  ans.SNum[m] -= 10;
                  ans.SNum[m-1] += ((ans.SNum[m] - '0') / 10);
              }
           }
           if(((c - '0') * (num1.SNum[j] - '0')) >= 10)
           {
               ans.SNum[m] += (((c - '0') * (num1.SNum[j] - '0')) % 10);
               if(ans.SNum[m] > '0' + 10)
              {
                  ans.SNum[m] -= 10;
                  ans.SNum[m-1] += ((ans.SNum[m] - '0') / 10);
              }
              ans.SNum[m-1] += (((num1.SNum[j] - '0') * (c - '0')) / 10);
              /*if(ans.SNum[m-1] > '0' + 10)
              {
                  ans.SNum[m-1] -= 10;
                  ans.SNum[m-2] += ((ans.SNum[m-1] - '0') / 10);
              }*/
           }
       }
       for(int l = 0 ; l < f ; l++)
            ans = ans + '0';
       temp = temp + ans;
   }
   return temp;
}

Bignum &Bignum::operator=(string SNumber)
{
    if(SNumber[0] >= '0' && SNumber[0] <= '9')
    {
        SNum = SNumber;
        size = SNumber.length();
        plus_negetive = 1;
    }
    if(SNumber[0] == '+')
    {
        for(int i = 1 ; i < SNumber.length() ; i++)
            SNum += SNumber[i];
        size = SNumber.length() - 1;
        plus_negetive = 1;
    }
    if(SNumber[0] == '-')
    {
        for(int i = 1 ; i < SNumber.length() ; i++)
            SNum += SNumber[i];
        size = SNumber.length() - 1;
        plus_negetive = 0;
    }

}


Bignum &Bignum::operator=(long long int z)
{
    SNum = to_string(z);
    size = SNum.length();
    if(z > 0)
        plus_negetive = 1;
    if(z < 0)
        plus_negetive = 0;
    return *this;
}


Bignum &Bignum::operator=(Bignum num)
{
    SNum = num.SNum;
    size = num.size;
    plus_negetive = num.plus_negetive;
    return *this;
}

int operator<=(Bignum num1 , Bignum num2)
{
    if(num1 < num2)
        return 1;
    if(num1 > num2)
        return 0;
    if(num1 == num2)
        return 1;
}

int operator>=(Bignum num1 , Bignum num2)
{
    if(num1 > num2)
        return 1;
    if(num1 < num2)
        return 0;
    if(num1 == num2)
        return 1;
}

int operator>(Bignum num1 , Bignum num2)
{
    if(num2.size < num1.size)
        return 1;
    else if(num2.size > num1.size)
        return 0;
    if(num2.size == num1.size)
        for(int i = 0 ; i < num1.size ; i++)
        {
            if(num2.SNum[i] < num1.SNum[i])
                return 1;
            if(num2.SNum[i] > num1.SNum[i])
                return 0;
        }
    return 0;
}

int operator<(Bignum num1 , Bignum num2)
{
    if(num2.size > num1.size)
        return 1;
    else if(num2.size < num1.size)
        return 0;
    if(num2.size == num1.size)
        for(int i = 0 ; i < num1.size ; i++)
        {
            if(num2.SNum[i] > num1.SNum[i])
                return 1;
            if(num2.SNum[i] < num1.SNum[i])
                return 0;
        }
    return 0;
}


int operator==(Bignum num1 , Bignum num2)
{
    if((num1.SNum == num2.SNum) && (num1.size == num2.size) && (num1.plus_negetive == num2.plus_negetive))
        return 1;
    else
        return 0;
}

int operator==(Bignum num1 , long long int z)
{
    Bignum num2(0);
    num2 = z;
    if((z == 0) && (num1.SNum == "0"))
    {
        return 1;
    }
    if(z > 0)
        num1.plus_negetive = 1;
    if(z < 0)
        num1.plus_negetive = 0;
    if(num1 == num2)
        return 1;
    else
        return 0;
}


int Bignum::operator[](int z)
{
    return (SNum[z-1] - '0');
}


ostream &operator<<(ostream &output, Bignum num)
{
    if(num == 0)
    {
        output << "0" << endl;
        return output;
    }
    if(num.plus_negetive == 1)
        cout << '+';
    if(num.plus_negetive == 0)
        cout << '-';
    if(num.SNum[0] == '0')
    {
        int m;
        for(int i = 0 ; i < num.size ; i++)
            if(num.SNum[i] > '0' && num.SNum[i] <= '9')
            {
                m = i;
                break;
            }
        for(int i = m , j = 0; i < num.size + m ; i++ , j++)
            num.SNum[j] = num.SNum[i];
    }
    output << num.SNum << endl;
    return output;
}

istream &operator>>(istream &input , Bignum &num)
{
    input >> num.SNum;
//    cout << num.SNum.length() << endl;
    num.size = num.SNum.length();
    return input;
}

Bignum operator+=(Bignum num1 , Bignum num2)
{
    num1 = num1 + num2;
    return num1;
}

Bignum operator-=(Bignum num1 , Bignum num2 )
{
    num1 = num1 - num2;
    return num1;
}

Bignum operator*=(Bignum num1 , Bignum num2 )
{
    num1 = num1 * num2;
    return num1;
}

Bignum operator+=(Bignum num1, long long int z)
{
    num1 = num1 + z;
    return num1;
}

Bignum operator-=(Bignum num1, long long int z)
{
    num1 = num1 - z;
    return num1;
}


Bignum operator*=(Bignum num1 , long long int z)
{
    num1 = num1 * z;
    return num1;
}

Bignum operator-(Bignum num1, long long int z)
{
    Bignum num2(z);
    Bignum num3(0);
    num3 = num1 - num2;
    return num3;
}

Bignum operator*(Bignum num1, long long int z)
{
    Bignum num2 = z;
    Bignum num3(0);
    num3 = num1 * num2;
    return num3;
}

Bignum operator++(Bignum num)
{
    Bignum num2(1);
    return (num + num2);
}

Bignum operator--(Bignum num)
{
    Bignum num2(1);
    return (num - num2);
}

int operator!=(Bignum num1 , Bignum num2)
{
    if(num1 == num2)
        return 0;
    else
        return 1;
}

int operator!=(Bignum num, long long int z)
{
    if(num == z)
        return 0;
    else
        return 1;
}

























