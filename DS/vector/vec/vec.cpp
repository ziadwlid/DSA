#include "vec.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>


using namespace std;

static void my_assert(bool condition, const char *message)
{
    if (!condition)
    {
        cout << "Assertion failed: " << message << endl;
        exit(1);
    }
}

Vector::Vector(int size)
{
    if (size < 0)
        size = 1;

    this->size = size;
    capacity = size + 10;
    arr = new int[capacity]{};
}

Vector::~Vector()
{
    delete[] arr;
}

void Vector::expand_capacity()
{
    capacity *= 2;

    int *arr2 = new int[capacity]{};

    for (int i = 0; i < size; ++i)
        arr2[i] = arr[i];

    swap(arr, arr2);
    delete[] arr2;
}

void Vector::push_back(int value)
{
    if (size == capacity)
        expand_capacity();

    arr[size++] = value;
}

int Vector::get_size()
{
    return size;
}

int Vector::get(int idx)
{
    my_assert(0 <= idx && idx < size, "Index out of range");
    return arr[idx];
}

void Vector::set(int idx, int val)
{
    my_assert(0 <= idx && idx < size, "Index out of range");
    arr[idx] = val;
}

int Vector::find(int value)
{
    for (int i = 0; i < size; ++i)
        if (arr[i] == value)
            return i;

    return -1;
}

void Vector::insert(int idx, int val)
{
    my_assert(0 <= idx && idx <= size, "Index out of range");

    if (size == capacity)
        expand_capacity();

    for (int p = size - 1; p >= idx; --p)
        arr[p + 1] = arr[p];

    arr[idx] = val;
    ++size;
}

void Vector::print()
{
    cout << "index: ";
    for (int i = 0; i < size; ++i)
        cout << i << " | ";

    cout << "\nvalue: ";

    for (int i = 0; i < size; ++i)
        cout << arr[i] << " | ";

    cout << "\n";
}
