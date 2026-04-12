#include <iostream>
using namespace std;

struct Node {
    int data {};
    Node * next {};
    Node (int data) : data (data){}
    ~Node (){
        cout << "Node data is -> "  << data << " address -> " << this << "\n";
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
        void insert_end (int value){
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
        void get_nth_back(int val){
            if (val <= 0 || val > length){
                cout << "Invalid input\n";
                return;
            }
            Node* end = tail;
            Node* start = head;
            for (int i = 0; i < val - 1; ++i){
                end = end->next;
            }
            cout << end->data << "\n";

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
    sll.insert_end(1);
    sll.insert_end(2);
    sll.insert_end(3);
    sll.get_nth_back(1);
    return 0;
}