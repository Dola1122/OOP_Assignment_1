#include <iostream>
#include <string>
#include <cstring>

using namespace std;


// اكتبو اسماء الفانكشن و الفاريبلز بال camelCase , myVariableNameIsLikeThis
// اسماء الclasses بال capitalized , MyClassName

class BigDecimalInt {
public:
    string num;
    int signOfNumber = 1; // I think it's value should be 1 or -1 only

    BigDecimalInt(string decStr) {
        this->num = decStr;
    };

    //initialize from integer constructor : I don't know how to do it btw
    BigDecimalInt(int decInt);


    // دي ميثود الجمع انا كنت حاولت فيها قبل كدا بس كملو انتو بقا
    BigDecimalInt operator+(BigDecimalInt anotherDec) {
        BigDecimalInt sum("");
        if(anotherDec.num.length()>num.length()){
            int numberOfZeros = anotherDec.num.length()-num.length();
            string zero="";
            for(int i=0; i<numberOfZeros ; i++) 
            zero = zero + "0";
            zero = zero + num;
            cout<<zero<<endl;
            num=zero;
            cout<<num<<endl;
        }
        else if(anotherDec.num.length()<num.length()){
            int numberOfZeros = num.length()-anotherDec.num.length();
            string zero="";
            for(int i=0; i<numberOfZeros ; i++) 
            zero = zero + "0";
            zero = zero + anotherDec.num;
            anotherDec.num=zero;
        }
        
        int sum_of_digit;

        int carry = 0;
        for (int i =num.length()-1 ; i>=0;i--) {
            sum_of_digit = int(num[i]-'0' ) + int(anotherDec.num[i]-'0' ) + carry;
            sum.num = to_string((sum_of_digit % 10))+ sum.num ;
            carry = sum_of_digit / 10;

        }
        if (carry > 0) {
            sum.num = to_string(carry) + sum.num;
        }
        return sum;
        
    }


    BigDecimalInt operator-(BigDecimalInt anotherDec);

    bool operator<(BigDecimalInt anotherDec) {
        if (signOfNumber < anotherDec.signOfNumber) {
            return true;
        } else if (signOfNumber > anotherDec.signOfNumber) {
            return false;
        } else if ((num.length() < anotherDec.num.length() && signOfNumber == 1) ||
                   (num.length() > anotherDec.num.length() && signOfNumber == -1)) {
            return true;
        }
        else if ((num.length() < anotherDec.num.length() && signOfNumber == -1) ||
                 (num.length() > anotherDec.num.length() && signOfNumber == 1)){
            return false;
        }
        else {
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

    int size();

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
    BigDecimalInt num1("999");
    num1.signOfNumber = -1;
    BigDecimalInt num2("12");
    num2.signOfNumber = -1;
    cout<<num1 + num2<<endl;
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
