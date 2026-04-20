#include <iostream>
#include <cassert>
using namespace std;

class Stack {
private:
	int size { };
	int added_elements { };
	int* array { };
	bool isFull() {
		return added_elements == size;
		/*
		Time comlexity O(1)
		*/
	}
	

	bool isEmpty() {
		return added_elements == 0;
		/*
		Time comlexity O(1)
		*/
	}
public:
	Stack(int size) :
			size(size), added_elements(0) {
		array = new int[size];
	}

	~Stack() {
		delete[] array;
	}

	bool push(int x) {
		if (isFull()) return false;
		for (int i = added_elements; i > 0 ; --i){
			array[i] = array[i - 1];
		}
		array[0] = x;
		added_elements++;
		return true;
		/*
		time complexity O(n)
		*/
	}

	bool pop() {
		if (isEmpty()) return false;
		for (int i = 0; i < added_elements - 1; ++i){
			array[i] = array [i + 1];
		}
		added_elements--;
		return true;
		/*
		Time comlexity O(n)
		*/
	}

	bool peek(int & value) {
		if (isEmpty()) return false;
		value = array[0];
		return true;
		/*
		Time comlexity O(1)
		*/
	}

	void display() {
        for (int i = 0; i < added_elements; i++)
            cout << array[i] << " ";
        cout << "\n";
		/*
		Time comlexity O(n)
		*/
    }
};

int main() {
	Stack stk(3);
	stk.push(10);
	stk.push(20);
	stk.push(30);
	stk.display();
	int val {0};
	stk.peek(val);
	stk.pop();
	stk.display();

	return 0;
}