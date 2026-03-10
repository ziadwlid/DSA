#include <iostream>
#include <cstdlib>
using namespace std;

void assert(bool condition, const char *message)
{
    if (!condition)
    {
        cout << "Assertion failed: " << message << endl;
        exit(1);
    }
}

class Vector
{
private:
    int *arr{nullptr};
    int size{0};
    int capacity{};

public:
    Vector(int size) : size(size)
    {

        if (size < 0)
            size = 1;
        capacity = size + 10;
        arr = new int[capacity]{};
    }

    void expand_capacity()
    {
        capacity *= 2;
        cout << "expand capacity to " << capacity << "\n";
        int *arr2 = new int[capacity]{};
        for (int i = 0; i < size; ++i)
        {
            arr2[i] = arr[i];
        }
        swap(arr, arr2);
        delete[] arr2;
    }

    void puch_back(int value)
    {
        if (size == capacity)
            expand_capacity();
        arr[size++] = value;
    }

    ~Vector()
    {
        delete[] arr;
        arr = nullptr;
    }

    int get_size()
    {
        return size;
    }

    int get(int idx)
    {
        assert(0 <= idx && idx < size, "Index out of range in get()");
        return arr[idx];
    }
    int get_back(){
        return arr[size-1];
    }
    int get_front(){
        return arr[0];
    }

    void set(int idx, int val)
    {
        assert(0 <= idx && idx < size, "Index out of range in set()");
        arr[idx] = val;
    }

    void print()
    {
        cout << "index: ";
        for (int i = 0; i < size; ++i){
            cout << i << " | ";
        }
        cout << "\n" << "value: ";
        for (int i = 0; i < size; ++i)
            cout << arr[i] << " | ";
        cout << "\n";
    }

    int find(int value)
    {
        for (int i = 0; i < size; ++i)
            if (arr[i] == value)
                return i;
        return -1;
    }
    void insert(int idx, int val)
    {
        assert(0 <= idx && idx <= size, "Index out of range");

        if (size == capacity)
            expand_capacity();
        for (int i = size - 1; i >= idx; --i)
        {
            arr[i + 1] = arr[i];
        }
        arr[idx] = val;
        ++size;
    }
};

int main()
{
    Vector v(10);
    for (int i = 0; i < 10; ++i)
    {
        v.set(i, i);
    }
    v.print();
    v.insert(5, 55);
    v.print();
    return 0;
}
