#include <iostream>
#include <cassert>
#include <string>
using namespace std;

class Stack
{
private:
    int size{};
    int top{};
    char *array{};

    bool isFull()
    {
        return top == size - 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

public:
    Stack(int size) : size(size), top(-1) { array = new char[size]; }

    ~Stack()
    {
        delete[] array;
    }

    bool push(char x)
    {
        if (isFull())
            return false;
        array[++top] = x;
        return true;
    }

    bool pop(char &value)
    {
        if (isEmpty())
            return false;
        value = array[top--];
        return true;
    }

    bool peek(char &value)
    {
        if (isEmpty())
            return false;
        value = array[top];
        return true;
    }
};

int main()
{
    string str;
    getline(std::cin, str);
    Stack stk(str.length());
    for (int i = 0; i < (int)str.length(); ++i)
    {
        if (str[i] != ' ')
        {
            stk.push(str[i]);
        }
        else
        {
            char ch;
            while (stk.pop(ch))
            {
                std::cout << ch;
            }
            std::cout << " ";
        }
    }

    char ch;
    while (stk.pop(ch))
    {
        std::cout << ch;
    }
    std::cout << " \n";
    return 0;
}