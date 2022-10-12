#include <iostream>
#include <string>

using namespace std;


// اكتبو اسماء الفانكشن و الفاريبلز بال camelCase , myVariableNameIsLikeThis
// اسماء الclasses بال capitalized , MyClassName

class BigDecimalInt {
public:
    string num;
    int signOfNumber = 1; // I think it's value should be 1 or -1 only
    int sizeOfNumber;

    BigDecimalInt(string decStr) {
        this->num = decStr;
    };

    //initialize from integer constructor : I don't know how to do it btw
    BigDecimalInt (int decInt);


    // دي ميثود الجمع انا كنت حاولت فيها قبل كدا بس كملو انتو بقا
    BigDecimalInt operator+(BigDecimalInt anotherDec) {
        BigDecimalInt sum("");
        int carry = 0;
        for (int i = num.length() - 1; i >= 0; i--) {
            int sum_of_digit;
            sum_of_digit = int(num[i] - '0') + int(anotherDec.num[i] - '0') + carry;
            sum.num = to_string((sum_of_digit % 10)) + sum.num;
            carry = sum_of_digit / 10;
        }
        if (carry > 0) {
            sum.num = to_string(carry) + sum.num;
        }
        return sum;
    }


    BigDecimalInt operator-(BigDecimalInt anotherDec);

    bool operator<(BigDecimalInt anotherDec);

    bool operator>(BigDecimalInt anotherDec);

    bool operator==(BigDecimalInt anotherDec);

    BigDecimalInt operator=(BigDecimalInt anotherDec);

    int size();

    int sign();

    // You will also need to overwrite the << operator as follows: (as friend or external function)
    // k.
    friend ostream &operator<<(ostream &out, BigDecimalInt b);

};

int main() {
    BigDecimalInt num1("99910356");
    BigDecimalInt num2("12899837");
    BigDecimalInt num3 = num1 + num2;
    cout << num3.num << endl;
    return 0;
}
