#include <iostream>
#include <cassert>

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


char get_open_match(char ch) {
	if (ch == ')')
		return '(';
	if (ch == ']')
		return '[';
	return '{';
}

bool isValid(std::string str) {
	Stack parentheses(str.size());

	for (int i = 0; i < (int) str.size(); ++i) {
		char ch = str[i];

		if (ch == '(' || ch == '[' || ch == '{')
			parentheses.push(ch);
		else if (parentheses.isEmpty() || parentheses.pop() != get_open_match(ch))
			return false;	// There must be an open match of the right type
	}
	return parentheses.isEmpty();
}
int main()
{
    std::string str;
    std::cin >> str;
    Stack stk(str.length());
    std::cout << isValid(str) << "\n";
    return 0;
}