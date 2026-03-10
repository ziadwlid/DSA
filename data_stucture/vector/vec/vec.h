#ifndef VEC_H_
#define VEC_H_

class Vector
{
private:
    int *arr;
    int size;
    int capacity;
    void expand_capacity();

public:
    Vector(int size);
    ~Vector();

    void push_back(int value);
    int get_size();
    int get(int idx);
    void set(int idx, int val);
    int find(int value);
    void insert(int idx, int val);
    void print();
};

#endif
