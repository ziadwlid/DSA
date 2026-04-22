#include <iostream>
#include <cassert>
#include <algorithm>

class Stack
{
private:
    int size{};
    int top{};
    char *array{};

public:
    Stack(int size) : size(size), top(-1)
    {
        array = new char[size];
    }

    ~Stack()
    {
        delete[] array;
    }

    void push(char x)
    {
        assert(!isFull());
        array[++top] = x;
    }

    int pop()
    {
        assert(!isEmpty());
        return array[top--];
    }

    int peek()
    {
        assert(!isEmpty());
        return array[top];
    }

    int isFull()
    {
        return top == size - 1;
    }

    int isEmpty()
    {
        return top == -1;
    }

    void display()
    {
        for (int i = top; i >= 0; i--)
            std::cout << array[i] << " ";
        std::cout << "\n";
    }
    void rev_display()
    {
        for (int i = 0; i <= top; i++)
        {
            std::cout << array[i] << " ";
        }
        std::cout << "\n";
    }
};
std::string removeDuplicates(std::string S){
    Stack stk(S.length());
    std::string out;
    for (int i = 0; i < (int)S.length(); i++){
        char ch = S[i];
        if (stk.isEmpty() || ch != stk.peek()) stk.push(ch);
        else if (ch == stk.peek()) stk.pop();
    }
     while (!stk.isEmpty()) {
        out += stk.pop();
    }
    std::reverse(out.begin(), out.end());
    return out;
}
int main()
{
    removeDuplicates ("abbaca");
    return 0;
}