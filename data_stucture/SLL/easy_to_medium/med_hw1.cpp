#include <iostream>
class LinkedList
{
private:
    struct Node
    {
        int data{};
        Node *next{};
        Node(int val) : data(val), next(nullptr) {};
    };
    Node *head{};
    Node *tail{};
    int length{0};

public:
    void insert_back(int val)
    {
        Node *item = new Node(val);
        if (!head)
        {
            head = tail = item;
        }
        else
        {
            tail->next = item;
            tail = item;
        }
        ++length;
    }
    void print()
    {
        Node *current = head;
        while (current)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
    }
    void delete_node_with_key(int value) {
    if (!head) return;  // empty list

    // Case 1: the node to delete is the head
    if (head->data == value) {
        delete_first();
        return;
    }
    Node* prev = head;
    Node* cur = head->next;

    while (cur) {
        if (cur->data == value) {
            prev->next = cur->next;
            if (cur == tail)
                tail = prev;

            delete_node(cur);  
            return; 
        }

        prev = cur;
        cur = cur->next;
    }
}
    void delete_node(Node *node)
    {
        --length;
        delete node;
    }
    Node *get_nth(int n)
    {
        Node *cur = head;
        for (int i = 1; i < n && cur; i++)
        {
            cur = cur->next;
        }
        return cur;
    }
    void delete_first()
    {
        if (head)
        {
            Node *cur = head;
            head = head->next;
            delete_node(cur);
            if (!head)
            {
                tail = nullptr;
            }
        }
    }
    void delete_last()
    {
        if (length <= 1)
        {
            delete_first();
            return;
        }
        Node *prevoius = get_nth(length - 1);
        delete_node(tail);
        tail = prevoius;
        tail->next = nullptr;
    }
    ~LinkedList()
    {
        Node *current = head;
        while (current)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }
};

int main()
{
    LinkedList sll;
    sll.insert_back(11);
    sll.insert_back(2);
    sll.insert_back(15);
    sll.insert_back(2);
    sll.delete_node_with_key(2);
    sll.print();
    return 0;
}