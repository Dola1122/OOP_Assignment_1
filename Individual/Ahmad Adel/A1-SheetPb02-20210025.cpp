#include <iostream>
#include <vector>

using namespace std;

vector<string> split(string target, string delimiter) {
    vector<string> v;
    string element = "";

    for (char i: target) {
        if (i != delimiter[0]) {
            element += i;
        } else {
            v.push_back(element);
            element = "";
        }
    }
    v.push_back(element);
    return v;
}

int main()
{
       vector<string> vic1 = split("do re mi fa so la ti do", " ");
       for(string i : vic1)
           cout<<i<<endl;

}