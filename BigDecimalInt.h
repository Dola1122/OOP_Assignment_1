#ifndef BIGDECIMALINT_H
#define BIGDECIMALINT_H

using namespace std;

class BigDecimalInt
{
    string num;
    int signOfNumber = 1, sizeOfNumber = 1;

public:
    BigDecimalInt(string decStr);      // constructor from string
    BigDecimalInt(int decInt);         // constructor from int
    BigDecimalInt operator+(BigDecimalInt anotherDec);
    BigDecimalInt operator-(BigDecimalInt anotherDec);
    bool operator<(BigDecimalInt anotherDec);
    bool operator>(BigDecimalInt anotherDec);
    bool operator==(BigDecimalInt anotherDec);
    BigDecimalInt operator=(BigDecimalInt anotherDec);
    int size();
    int sign();
    friend ostream& operator<<(ostream& out, BigDecimalInt b);
};

bool validateInput(string num);
#endif