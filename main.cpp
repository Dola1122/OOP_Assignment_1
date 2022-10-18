#include <iostream>
#include <string>
#include <cstring>
#include <regex>

using namespace std;

bool validateInput(string num)
{
    regex valid("[+-]?[0-9]+");
    return regex_match(num, valid);   
}

// اكتبو اسماء الفانكشن و الفاريبلز بال camelCase , myVariableNameIsLikeThis
// اسماء الclasses بال capitalized , MyClassName

class BigDecimalInt {
    string num;
    int signOfNumber = 1; // I think it's value should be 1 or -1 only
    int sizeOfNumber = 1;

public:
    BigDecimalInt(string decStr) {
        if(validateInput(decStr))
            {
                string temp;
                int counter = 0;
                if (num[0] == '-')
                {
                    signOfNumber = -1;
                }
                if (decStr.length() == 1 )
                {
                    this->num = decStr;
                }
                else
                {
                    while (decStr[counter] == '0' and counter < decStr.length()) // to remove the left zeros
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
    };

    //initialize from integer constructor : I don't know how to do it btw
    BigDecimalInt(int decInt)
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


    // دي ميثود الجمع انا كنت حاولت فيها قبل كدا بس كملو انتو بقا
    BigDecimalInt operator+(BigDecimalInt anotherDec) {
        BigDecimalInt sum("");
        if (anotherDec.num.length() > num.length()) {
            int numberOfZeros = anotherDec.num.length() - num.length();
            string zero = "";
            for (int i = 0; i < numberOfZeros; i++)
                zero = zero + "0";
            zero = zero + num;
            cout << zero << endl;
            num = zero;
            cout << num << endl;
        } else if (anotherDec.num.length() < num.length()) {
            int numberOfZeros = num.length() - anotherDec.num.length();
            string zero = "";
            for (int i = 0; i < numberOfZeros; i++)
                zero = zero + "0";
            zero = zero + anotherDec.num;
            anotherDec.num = zero;
        }

        int sum_of_digit;

        int carry = 0;
        for (int i = num.length() - 1; i >= 0; i--) {
            sum_of_digit = int(num[i] - '0') + int(anotherDec.num[i] - '0') + carry;
            sum.num = to_string((sum_of_digit % 10)) + sum.num;
            carry = sum_of_digit / 10;

        }
        if (carry > 0) {
            sum.num = to_string(carry) + sum.num;
        }
        return sum;

    }


    BigDecimalInt operator-(BigDecimalInt anotherDec) {
        if (anotherDec.num.length() > num.length()) {
            int numberOfZeros = anotherDec.num.length() - num.length();
            string zero = "";
            for (int i = 0; i < numberOfZeros; i++)
                zero = zero + "0";
            zero = zero + num;
            cout << zero << endl;
            num = zero;
            cout << num << endl;
        } else if (anotherDec.num.length() < num.length()) {
            int numberOfZeros = num.length() - anotherDec.num.length();
            string zero = "";
            for (int i = 0; i < numberOfZeros; i++)
                zero = zero + "0";
            zero = zero + anotherDec.num;
            anotherDec.num = zero;
        }

        BigDecimalInt result(""), newNumber(num);
        newNumber.signOfNumber = 1;
        result.signOfNumber = 1;
        string secondNumber9sComp = "";
        if (newNumber > anotherDec) {
            for (int i = 0; i < anotherDec.num.length(); i++) {
                secondNumber9sComp += to_string('9' - anotherDec.num[i]);
            }

            anotherDec.num = secondNumber9sComp;

            BigDecimalInt sum("");
            int sum_of_digit;

            int carry = 1;
            for (int i = newNumber.num.length() - 1; i >= 0; i--) {
                sum_of_digit = int(newNumber.num[i] - '0') + int(anotherDec.num[i] - '0') + carry;
                sum.num = to_string((sum_of_digit % 10)) + sum.num;
                carry = sum_of_digit / 10;

            }
            return sum;
        } else {
            if(anotherDec > newNumber){
                result.signOfNumber = -1;
            }
            for (int i = 0; i < newNumber.num.length(); i++) {
                secondNumber9sComp += to_string('9' - newNumber.num[i]);
            }

            newNumber.num = secondNumber9sComp;

            BigDecimalInt sum("");
            int sum_of_digit;

            int carry = 1;
            for (int i = anotherDec.num.length() - 1; i >= 0; i--) {
                sum_of_digit = int(anotherDec.num[i] - '0') + int(newNumber.num[i] - '0') + carry;
                sum.num = to_string((sum_of_digit % 10)) + sum.num;
                carry = sum_of_digit / 10;

            }
            return sum;

        }
    };

    bool operator<(BigDecimalInt anotherDec) {
        if (signOfNumber < anotherDec.signOfNumber) {
            return true;
        } else if (signOfNumber > anotherDec.signOfNumber) {
            return false;
        } else if ((num.length() < anotherDec.num.length() && signOfNumber == 1) ||
                   (num.length() > anotherDec.num.length() && signOfNumber == -1)) {
            return true;
        } else if ((num.length() < anotherDec.num.length() && signOfNumber == -1) ||
                   (num.length() > anotherDec.num.length() && signOfNumber == 1)) {
            return false;
        } else {
            for (int i = 0; i < anotherDec.num.length(); i++) {
                if (int(anotherDec.num[i] - '0') * anotherDec.signOfNumber > int(num[i] - '0') * signOfNumber) {
                    return true;
                } else if (anotherDec.num[i] == num[i]) {
                    continue;
                } else {
                    return false;
                }
            }
        }
        return false;
    }


    bool operator>(BigDecimalInt anotherDec) {
        if (num.length() > anotherDec.num.length()) {
            return true;
        } else {
            for (int i = 0; i < num.length(); i++) {
                if (int(num[i] - '0') * signOfNumber > int(anotherDec.num[i] - '0') * anotherDec.signOfNumber) {
                    return true;
                } else if (num[i] == anotherDec.num[i]) {
                    continue;
                } else {
                    return false;
                }
            }
        }
        return false;
    }

    bool operator==(BigDecimalInt anotherDec) {
        if (num.length() != anotherDec.num.length()) {
            return false;
        } else if (signOfNumber != anotherDec.signOfNumber) {
            return false;
        } else {
            for (int i = 0; i < num.length(); i++) {
                if (num[i] == anotherDec.num[i]) {
                    continue;
                } else {
                    return false;
                }
            }
        }
        return true;
    }

    BigDecimalInt operator=(BigDecimalInt anotherDec) {
        num = anotherDec.num;
        signOfNumber = anotherDec.signOfNumber;
        return *this;
    }

    int size()
    {
        return sizeOfNumber;
    }

    int sign() {
        return signOfNumber;
    }

    // You will also need to overwrite the << operator as follows: (as friend or external function)
    // k.
    friend ostream &operator<<(ostream &out, BigDecimalInt bigInt);

};

ostream &operator<<(ostream &out, BigDecimalInt b) {
    if (b.signOfNumber == -1) {
        out << '-';
    }
    for (int i = 0; i < b.num.size(); i++) {
        out << b.num[i];
    }
    return out;
}

int main() {

    BigDecimalInt num1("2660");
    //num1.signOfNumber = 1;
    BigDecimalInt num2("200");
    //num2.signOfNumber = 1;
    BigDecimalInt num3(0);
    cout << num1 - num2 << endl;
    cout << num3 << ' ' << num3.size();
    //num2 = num1;
    //cout << (num1 < num2) << endl;
    //cout << num1 << ' ' << num2;
    // if (num1 > num2)
    // {
    //     cout << "True!";
    // }
    // else
    // {
    //     cout << "False!";
    // }

    // if (num1 == num2)
    // {
    //     cout << "They are equal!";
    // }
    // else
    // {
    //     cout << "they are not equal!";
    // }

    return 0;
}
