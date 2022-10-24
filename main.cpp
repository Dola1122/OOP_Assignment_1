#include <iostream>
#include <string>
#include <cstring>
#include <regex>
#include "BigDecimalInt.h"
#include "BigDecimalInt.cpp"

using namespace std;

int main()
{

    // BigDecimalInt num0("10");
    // BigDecimalInt num1("-10");
    // BigDecimalInt num2("100");
    // BigDecimalInt num3("0050");
    // BigDecimalInt num4("-050");
    // BigDecimalInt num5("00");

    // cout << (num2 + num1) << endl;
    // cout << num3 << ' ' << num3.size();
    // num2 = num1;
    // cout << (num1 < num2) << endl;
    // cout << num1 << ' ' << num2;
    // if (num1 > num2)
    // {
    //     cout << "True!";
    // }
    // else
    // {
    //     cout << "False!";
    // }

    // cout << num1 + num1 << endl;
    // cout << num1 + num2 << endl;
    // cout << num0 - num1 << endl;
    // cout << num0 + num4 << endl;
    // cout << num3 - num4 << endl;
    // cout << num3 + num4 << endl;

    BigDecimalInt num1("1000");
    BigDecimalInt num2("20");
    BigDecimalInt num3("1000");
    BigDecimalInt num4("-20");
    BigDecimalInt num5("00010");
    BigDecimalInt num6("00020");
    BigDecimalInt num7("-00010");
    BigDecimalInt num8("-00020");
    
    cout << num1 + num2 << endl;
    cout << num4 + num1 << endl;
    cout << num2 + num3 << endl;
    cout << num4 - num8 << endl
         << endl;

    cout << num1 - num2 << endl;
    cout << num4 - num1 << endl;
    cout << num2 - num3 << endl;
    cout << num4 + num8 << endl;

    return 0;
}
