#include <iostream>
using namespace std;

struct Node {
    int data {};
    Node * next {};
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
        void insert (int value){
            Node *item = new Node(value);
            if (!head){
                head = tail = item;
            }
            else {
                tail ->next = item;
                tail = item;
                ++length;
            }
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
    sll.insert(1);
    sll.insert(10);
    sll.insert(88);
    sll.print();
    return 0;
}