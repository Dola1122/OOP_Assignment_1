#include <string>
#include <cstring>
#include <regex>
#include "BigDecimalInt.h"

using namespace std;

BigDecimalInt::BigDecimalInt(string decStr) // construct from a string
{
    if (validateInput(decStr))
    {
        string temp;
        int counter = 0;
        if (decStr[0] == '-')
        {
            this->signOfNumber = -1;
        }
        if (decStr.length() == 1)
        {
            this->num = decStr;
        }
        else
        {
            // to remove the left zeros // edit by dola to remove + and -
            while (decStr[counter] == '0' and counter < decStr.length() ||
                   decStr[counter] == '-' and counter < decStr.length() ||
                   decStr[counter] == '+' and counter < decStr.length())
            {
                counter++;
            }
            temp = decStr.substr(counter, decStr.length());

            this->num = temp;
            sizeOfNumber = decStr.length() - counter;
        }
    }
    else
    {
        this->num = "0";
    }
}

BigDecimalInt::BigDecimalInt(int decInt) // construct from an int
{
    if (decInt < 0)
    {
        signOfNumber = -1;
        this->num = to_string(decInt);
        this->num = num.substr(1, num.length());
        sizeOfNumber = num.size();
    }
    else
    {
        this->num = to_string(decInt);
        sizeOfNumber = num.size();
    }
}

BigDecimalInt BigDecimalInt::operator+(BigDecimalInt anotherDec)
{
    BigDecimalInt sum(""), temp = *this;
    sum.num = "";
    if (anotherDec.num.length() > num.length())
    {
        int numberOfZeros = anotherDec.num.length() - num.length();
        string zero = "";
        for (int i = 0; i < numberOfZeros; i++)
            zero = zero + "0";
        zero = zero + num;
        num = zero;
    }
    else if (anotherDec.num.length() < num.length())
    {
        int numberOfZeros = num.length() - anotherDec.num.length();
        string zero = "";
        for (int i = 0; i < numberOfZeros; i++)
            zero = zero + "0";
        zero = zero + anotherDec.num;
        anotherDec.num = zero;
    }
    int sum_of_digit;
    int carry = 0;

    if (signOfNumber == -1 and anotherDec.signOfNumber == -1)
    {
        for (int i = num.length() - 1; i >= 0; i--)
        {
            sum_of_digit = int(num[i] - '0') + int(anotherDec.num[i] - '0') + carry;
            sum.num = to_string((sum_of_digit % 10)) + sum.num;
            carry = sum_of_digit / 10;
        }
        if (carry > 0)
        {
            sum.num = to_string(carry) + sum.num;
        }
        sum.signOfNumber = -1;
    }
    else if (signOfNumber == -1 and anotherDec.signOfNumber == 1)
    {
        signOfNumber *= -1;
        sum = anotherDec - *this;
    }
    else if (signOfNumber == 1 and anotherDec.signOfNumber == -1)
    {
        anotherDec.signOfNumber *= -1;
        sum = *this - anotherDec;
    }
    else
    {
        for (int i = num.length() - 1; i >= 0; i--)
        {
            sum_of_digit = int(num[i] - '0') + int(anotherDec.num[i] - '0') + carry;
            sum.num = to_string((sum_of_digit % 10)) + sum.num;
            carry = sum_of_digit / 10;
        }
        if (carry > 0)
        {
            sum.num = to_string(carry) + sum.num;
        }
    }

    *this = temp;
    return sum;
}

BigDecimalInt BigDecimalInt::operator-(BigDecimalInt anotherDec)
{
    BigDecimalInt temp = *this;
    if (signOfNumber == -1 and anotherDec.signOfNumber == -1)
    {
        BigDecimalInt newNum(num);
        anotherDec.signOfNumber = 1;
        BigDecimalInt result = anotherDec - newNum;
        *this = temp;
        return result;
    }

    if (signOfNumber != anotherDec.signOfNumber)
    {
        int resultSign = signOfNumber;
        anotherDec.signOfNumber = 1;
        signOfNumber = 1;
        BigDecimalInt result = *this + anotherDec;
        result.signOfNumber = resultSign;
        *this = temp;
        return result;
    }

    if (anotherDec.num.length() > num.length())
    {
        int numberOfZeros = anotherDec.num.length() - num.length();
        string zero = "";
        for (int i = 0; i < numberOfZeros; i++)
            zero = zero + "0";
        num = zero + num;
    }
    else if (anotherDec.num.length() < num.length())
    {
        int numberOfZeros = num.length() - anotherDec.num.length();
        string zero = "";
        for (int i = 0; i < numberOfZeros; i++)
            zero = zero + "0";
        anotherDec.num = zero + anotherDec.num;
    }

    BigDecimalInt newNumber("");
    newNumber.num = num;
    string secondNumber9sComp = "";
    if (newNumber > anotherDec)
    {
        for (int i = 0; i < anotherDec.num.length(); i++)
        {
            secondNumber9sComp += to_string('9' - anotherDec.num[i]);
        }

        anotherDec.num = secondNumber9sComp;

        BigDecimalInt sum("");
        int sum_of_digit;
        sum.num = "";
        int carry = 1;
        for (int i = newNumber.num.length() - 1; i >= 0; i--)
        {
            sum_of_digit = int(newNumber.num[i] - '0') + int(anotherDec.num[i] - '0') + carry;
            sum.num = to_string((sum_of_digit % 10)) + sum.num;
            carry = sum_of_digit / 10;
        }
        BigDecimalInt result(sum.num);
        result.signOfNumber = sum.signOfNumber;
        *this = temp;
        return result;
    }
    else if (newNumber < anotherDec)
    {
        for (int i = 0; i < newNumber.num.length(); i++)
        {
            secondNumber9sComp += to_string('9' - newNumber.num[i]);
        }

        newNumber.num = secondNumber9sComp;

        BigDecimalInt sum("");
        int sum_of_digit;

        int carry = 1;
        sum.num = "";
        for (int i = anotherDec.num.length() - 1; i >= 0; i--)
        {
            sum_of_digit = int(anotherDec.num[i] - '0') + int(newNumber.num[i] - '0') + carry;
            sum.num = to_string((sum_of_digit % 10)) + sum.num;
            carry = sum_of_digit / 10;
        }
        sum.signOfNumber = -1;
        BigDecimalInt result(sum.num);
        result.signOfNumber = sum.signOfNumber;
        *this = temp;
        return result;
    }
    else
    {
        BigDecimalInt result("");
        *this = temp;
        return result;
    }
}

bool BigDecimalInt::operator<(BigDecimalInt anotherDec)
{
    if (signOfNumber < anotherDec.signOfNumber)
    {
        return true;
    }
    else if (signOfNumber > anotherDec.signOfNumber)
    {
        return false;
    }
    else if ((num.length() < anotherDec.num.length() && signOfNumber == 1) ||
             (num.length() > anotherDec.num.length() && signOfNumber == -1))
    {
        return true;
    }
    else if ((num.length() < anotherDec.num.length() && signOfNumber == -1) ||
             (num.length() > anotherDec.num.length() && signOfNumber == 1))
    {
        return false;
    }
    else
    {
        for (int i = 0; i < anotherDec.num.length(); i++)
        {
            if (int(anotherDec.num[i] - '0') * anotherDec.signOfNumber > int(num[i] - '0') * signOfNumber)
            {
                return true;
            }
            else if (anotherDec.num[i] == num[i])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    return false;
}

bool BigDecimalInt::operator>(BigDecimalInt anotherDec)
{
    if (anotherDec.signOfNumber < signOfNumber)
    {
        return true;
    }
    else if (anotherDec.signOfNumber > signOfNumber)
    {
        return false;
    }
    else if ((anotherDec.num.length() < num.length() && anotherDec.signOfNumber == 1) ||
             (anotherDec.num.length() > num.length() && anotherDec.signOfNumber == -1))
    {
        return true;
    }
    else if ((anotherDec.num.length() < num.length() && anotherDec.signOfNumber == -1) ||
             (anotherDec.num.length() > num.length() && anotherDec.signOfNumber == 1))
    {
        return false;
    }
    else
    {
        for (int i = 0; i < num.length(); i++)
        {
            if (int(num[i] - '0') * signOfNumber > int(anotherDec.num[i] - '0') * anotherDec.signOfNumber)
            {
                return true;
            }
            else if (num[i] == anotherDec.num[i])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    return false;
}

bool BigDecimalInt::operator==(BigDecimalInt anotherDec)
{
    if (num.length() != anotherDec.num.length())
    {
        return false;
    }
    else if (signOfNumber != anotherDec.signOfNumber)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < num.length(); i++)
        {
            if (num[i] == anotherDec.num[i])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

BigDecimalInt BigDecimalInt::operator=(BigDecimalInt anotherDec)
{
    num = anotherDec.num;
    signOfNumber = anotherDec.signOfNumber;
    return *this;
}

int BigDecimalInt::size()
{
    return sizeOfNumber;
}

int BigDecimalInt::sign()
{
    return signOfNumber;
}

ostream &operator<<(ostream &out, BigDecimalInt b)
{
    if (b.signOfNumber == -1)
    {
        out << '-';
    }
    for (int i = 0; i < b.num.size(); i++)
    {
        out << b.num[i];
    }
    return out;
}

bool validateInput(string num)
{
    regex valid("[+-]?[0-9]+");
    return regex_match(num, valid);
}
