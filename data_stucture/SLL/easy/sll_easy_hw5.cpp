#include <iostream>
using namespace std;

struct Node {
    int data {};
    Node * next {};
    Node (int data) : data (data){}
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
        bool is_same (LinkedList &other){
            if (length != other.length){
                return false;
            }
            Node *cur1 = head;
            Node *cur2 = other.head;
            while (cur1 && cur2){
                if (cur1->data != cur2->data){
                    return false;
                }
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
            return true;
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
    LinkedList sll1, sll2;
    cout << sll1.is_same(sll2) << "\n";
    sll1.insert(1);
    sll1.insert(2);
    cout << sll1.is_same(sll2) << "\n";
    sll2.insert(1);
    sll2.insert(2);
    cout << sll1.is_same(sll2) << "\n";
    return 0;
}