#include <bits/stdc++.h>

using namespace std;

template <typename t, int capacity>

class SmartArray
{
    t *ptr;
public:
    SmartArray()
    {
        ptr = new t[capacity];
    }
    ~SmartArray()
    {
        cout << "Destructor Called!" << '\n';
        delete[] ptr;
    }
    SmartArray(SmartArray &arr) // copy constructor
    {
        ptr = new t[capacity];
        for (int i = 0; i < capacity; i++)
        {
            this->ptr[i] = arr[i];
        }
    }

    t &operator[](int k)
    {
        if (k <= capacity)
        {
            return *(ptr + k);
        }
        return *ptr;
    }

    SmartArray &operator=(const t arr[])
    {
        delete[] ptr;       // to avoid memory leak
        ptr = new t[capacity];  // allocate new memory
        for (int i = 0; i < capacity; i++)
        {
            ptr[i] = arr[i];
        }
        return *this;
    }
    SmartArray &operator=(SmartArray &arr)
    {
        delete[] ptr;       // to avoid memory leak
        ptr = new t[capacity];  // allocate new memory
        for (int i = 0; i < capacity; i++)
        {
            ptr[i] = arr[i];
        }
        return *this;
    }

    int size()
    {
        return capacity;
    }
};

int main()
{
    SmartArray<int, 5> arr;
    SmartArray<int, 5> arr2;
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = i;
    }
    arr2 = arr;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < arr2.size(); i++)
    {
        cout << arr2[i] << ' ';
    }
    cout << endl;

    arr[0] = 10;
    cout << "\n\n";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < arr2.size(); i++)
    {
        cout << arr2[i] << ' ';
    }
    cout << endl;
    
    return 0;
}