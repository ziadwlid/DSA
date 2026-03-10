#include <iostream>
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

public:
    Vector(int size) : size(size)
    {

        if (size < 0)
            size = 1;
        capacity = size + 10;
        arr = new int[capacity]{};
    }


    ~Vector()
    {
        delete[] arr;
        arr = nullptr;
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

    void right_rotate (){
        int last {0};
        last = arr[size-1];
        arr[size-1] = 0;
        for (int i = size-2; i >= 0; --i){
            arr[i+1] = arr[i];
        }
        arr[0] = last;
        print();
    }
    

};

int main()
{
    Vector v(5);
    for (int i = 0; i < 5; ++i){
        v.set(i,i+1);
    }
    v.print();
    v.right_rotate();
    return 0;
}
