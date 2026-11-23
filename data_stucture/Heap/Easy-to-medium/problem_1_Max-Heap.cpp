#include <cassert>
#include <iostream>
using namespace std;
namespace Heap{
    class  MinHeap {
    private:
        int *array = nullptr;
        int size;
        int capacity = 1000;
    public:
        MinHeap() : array(new int[capacity]), size(0) {}
        MinHeap(const int capacity)
        : array(new int[capacity]), size(0), capacity(capacity) {
            assert(capacity > 0);
        }

        MinHeap(const MinHeap& other)
            : array(new int[capacity]),
              size(other.size),
              capacity(other.capacity) {

            for (int i = 0; i < size; i++) {
                array[i] = other.array[i];
            }
        }

        MinHeap& operator= (const MinHeap& other) {
            if (this == &other)
                return *this;
            size = other.size;
            capacity = other.capacity;
            for (int i = 0; i < capacity; i++) {
                array[i] = other.array[i];
            }
            return *this;
        }
        MinHeap& operator=(const int& x) {
            assert(x > 0);
            delete[] array;
            capacity = x;
            size = 0;
            array = new int[capacity];
            return *this;
        }
        MinHeap() {
            array = new int[capacity];
            size = 0;
        }
        ~MinHeap() {
            delete[] array;
            array = nullptr;
        }
        int left (const int& node)const {
            const int p = (node * 2) + 1;
            if (p >= size)
                return -1;
            return p;
        }
        int right (const int& node) const{
            const int p = (node * 2) + 2;
            if (p >= size)
                return -1;
            return p;
        }

        int parent (const int& node) {
            return node == 0 ? -1 : (node - 1) / 2;
        }
        void heapify_up (const int child_pos) {
            const int par_pos = parent(child_pos);
            if (child_pos == 0 || array[par_pos] < array[child_pos])
                return;
            swap (array[child_pos], array[par_pos]);
            heapify_up (par_pos);
        }
        void heapify_down (const int par_pos) {
            int child_pos = left(par_pos);
            const int right_child = right(par_pos);
            if (child_pos == -1) return;
            if (child_pos != -1 && array[right_child] < array[child_pos])
                child_pos = right_child;
            if (array[par_pos] < array[child_pos]) {
                swap (array[par_pos], array[child_pos]);
                heapify_down (child_pos);
            }
        }
        void push (const int& key) {
            assert (size +1 <= capacity);
            array[size++] = key;
            heapify_up (size-1);
        }
        void pop () {
            assert (!isEmpty());
            array[0] = array[--size];
            heapify_down (0);
        }
        int top () const {
            assert (!isEmpty());
            return array[0];
        }
        bool isEmpty () const {
            if (size == 0)
                return true;
            return false;
        }
    };

    class MaxHeap {
    private:
        int *array = nullptr;
        int size;
        int capacity = 1000;
        public:
        MaxHeap() : array(new int[capacity]), size(0) {}
        MaxHeap(const int capacity) : array(new int[capacity]), size(0), capacity(capacity) {}
        MaxHeap(const MaxHeap& other)
            : array(new int[capacity]),
              size(other.size),
              capacity(other.capacity) {

            for (int i = 0; i < size; i++) {
                array[i] = other.array[i];
            }
        }
        MaxHeap& operator= (const MaxHeap& other) {
            if (this == &other)
                return *this;
            size = other.size;
            capacity = other.capacity;
            for (int i = 0; i < capacity; i++) {
                array[i] = other.array[i];
            }
            return *this;
        }
        MaxHeap& operator=(const int& x) {
            assert(x > 0);
            delete[] array;
            capacity = x;
            size = 0;
            array = new int[capacity];
            return *this;
        }
        ~MaxHeap() {
            delete[] array;
            array = nullptr;
        }
        int left(int node) const {
            int p = node * 2 + 1;
            return p >= size ? -1 : p;
        }

        int right(int node) const {
            int p = node * 2 + 2;
            return p >= size ? -1 : p;
        }

        int parent(int node) const {
            return node == 0 ? -1 : (node - 1) / 2;
        }
        void heapify_up (const int child_pos) {
            const int par_pos = parent(child_pos);
            if (child_pos == 0) return;
            if (array[par_pos] >= array[child_pos])
                swap (array[par_pos], array[child_pos]);
            heapify_up (par_pos);
        }
        void heapify_down (const int par_pos) {
            int child_pos = left(par_pos);
            const int right_child = right(par_pos);
            if (child_pos == -1) return;
            if (child_pos != -1 && array[right_child] >= array[child_pos])
                child_pos = right_child;
            if (array[par_pos] > array[child_pos]) {
                swap (array[par_pos], array[child_pos]);
            }
            heapify_down (child_pos);
        }

        bool isEmpty () const {
            if (size == 0)
                return true;
            return false;
        }
        void pop () {
            assert (!isEmpty());
            array[0] = array[--size];
            heapify_down (0);
        }
        int push (const int& key) {
            assert (!isEmpty());
            array[size++] = key;
            heapify_up (size - 1);
        }
        int top () const {
            assert(!isEmpty());
            return array[0];
        }

    };
}

int main () {
    Heap::MinHeap heap1;
    Heap::MaxHeap heap2;
    return 0;
}