#include <iostream>
#include <string>

using namespace std;

struct BigDecimalInt {
    string num;
};

BigDecimalInt operator+(BigDecimalInt num1, BigDecimalInt num2) {
    BigDecimalInt sum;
    sum.num = "";
    int carry = 0;
    for (int i = num1.num.length() - 1; i >= 0; i--) {
        int sum_of_digit;
        sum_of_digit = int(num1.num[i] - '0') + int(num2.num[i] - '0') + carry;
        sum.num = to_string((sum_of_digit % 10)) + sum.num;
        carry = sum_of_digit / 10;
    }
    if (carry > 0) {
        sum.num = to_string(carry) + sum.num;
    }
    return sum;
}

int main() {
    BigDecimalInt num1;
    num1.num = "99910356";
    BigDecimalInt num2;
    num2.num = "12899837";
    BigDecimalInt num3 = num1 + num2;
    cout << num3.num << endl;
    return 0;
}
