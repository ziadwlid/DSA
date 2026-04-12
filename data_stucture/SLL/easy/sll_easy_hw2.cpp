#include <iostream>
using namespace std;

struct Node {
    int data {};
    Node * next {nullptr};
    Node (int data) : data (data){}
    ~Node (){
        cout << "Node data is :) -> "  << data << " address :) -> " << this << "\n";
    }
};
class LinkedList{
    private:
        Node *head {};
        Node *tail {};
        int length = 0;
        public:
        LinkedList (){}
        void print (){
            for (Node * cur = head;cur; cur = cur->next){
                cout << cur->data << " ";
            }
            cout << "\n";
        }
        // length = 0
        // length = 1
        // length = 2
        void insert_end (int value){
            Node *item = new Node(value);
            if (head == nullptr){
                head = tail = item;
                tail = item;
            }
            else {
                tail->next = item;
                tail = item;
            }
            ++length;
        }
        void insert_front (int value){
            Node *item = new Node(value);
                if (head == nullptr){
                    head = tail = item;
                }
                else {
                    item->next = head;
                    head = item;
                }
                ++length;
            }
        
        ~LinkedList (){
            while(head){
                Node* current = head->next;
                delete head;
                head = current;
            }
            cout << "Delete the nodes :)\n";
        }
};

int main (){
    LinkedList sll;
    sll.insert_front(30);
    sll.insert_front(15);
    sll.insert_end(10);
    sll.insert_end(20);
    sll.print();
    
    return 0;
}