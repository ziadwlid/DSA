#include <iostream>
#include <cassert>

class Stack {
private:
	int size { };
	int top { };
	int* array { };
public:
	Stack(int size) :
			size(size), top(-1) {
		array = new int[size];
	}

	~Stack() {
		delete[] array;
	}

	void push(int x) {
		assert(!isFull());
		array[++top] = x;
	}

	int pop() {
		assert(!isEmpty());
		return array[top--];
	}

	int peek() {
		assert(!isEmpty());
		return array[top];
	}

	int isFull() {
		return top == size - 1;
	}

	int isEmpty() {
		return top == -1;
	}

	void display() {
		for (int i = top; i >= 0; i--)
			std::cout << array[i] << " ";
		std::cout << "\n";
	}
    void rev_display (){
        for (int i = 0; i <= top; i++){
            std::cout << array [i] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    int input{};
    std::cin >> input;
    Stack stk(input);
    while (input > 0){
        int digit = input % 10;
        stk.push(digit);
        input /= 10;
    }
    stk.rev_display();
	return 0;
}