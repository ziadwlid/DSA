#include <iostream>
#include <cassert>

class Stack
{
private:
    int size{};
    int top1{};
    int top2{};
    int *array{};

    void push_stack1(int value)
    {
        assert(!isFull());
        array[++top1] = value;
    }

    void push_stack2(int value)
    {
        assert(!isFull());
        array[--top2] = value;
    }

public:
    Stack(int size) : size(size), top1(-1), top2(size)
    {
        array = new int[size];
    }

    ~Stack()
    {
        delete[] array;
    }

    void push(int id, int value)
    {
        assert(!isFull());
        if (id == 1)
            push_stack1(value);
        else if (id == 2)
            push_stack2(value);
    }

    int pop(int id)
    {
        assert(!isEmpty(id));

        if (id == 1)
            return array[top1--];
        else if (id == 2)
            return array[top2++];
        return -1;
    }

    int peek(int id)
    {
        if (id == 1)
            return array[top1];
        else if (id == 2)
            return array[top2];
        return -1;
    }

    bool isFull()
    {
        return top1 + 1 == top2;
    }

    bool isEmpty(int id)
    {
        if (id == 1)
            return top1 == -1;
        if (id == 2)
            return top2 == size;
        return true;
    }

    void display()
    {
        std::cout << "Stack 1: ";
        for (int i = top1; i >= 0; i--)
            std::cout << array[i] << " ";

        std::cout << "\nStack 2: ";
        for (int i = top2; i < size; i++)
            std::cout << array[i] << " ";

        std::cout << "\n";
    }
};

int main()
{
    Stack stk(10);
    stk.push(2, 5);
    stk.push(2, 6);
    stk.pop(2);
    stk.push(2, 7);
    stk.push(2, 9);
    stk.push(1, 4);
    stk.push(1, 6);
    stk.push(1, 8);
    stk.display();
    return 0;
}