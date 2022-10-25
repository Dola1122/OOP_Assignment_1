#include <iostream>

using namespace std;

bool bear(int n) {
    if (n == 42)
        return true;
    else if (n < 42)
        return false;
    if (n % 5 == 0) {
        if (bear(n - 42) == true)
            return true;
    }
    if (n % 3 == 0 || n % 4 == 0) {
        int digit1 = n % 10;
        int digit2 = (n % 100) / 10;

        if (digit1 * digit2 != 0) {
            if (bear(n - (digit1 * digit2)) == true)
                return true;
        }
    }
    if (n % 2 == 0) {
        if (bear(n / 2) == true)
            return true;
    }
    return false;
}

int main()
{
   cout << bear(250) << endl;  //is true
   cout << bear(42) << endl; //is true
   cout << bear(84) << endl; //is true
   cout << bear(53) << endl; //is false
   cout << bear(41) << endl; //is false

}
