#include <iostream>
class LinkedList
{
private:
    struct Node
    {
        int data{};
        Node *next{};
        Node *prev{};
        Node(int value) : data(value), next(nullptr), prev(nullptr) {};
    };
    Node *head{};
    Node *tail{};
    int length{0};

public:
    void insert_back(int value)
    {
        Node *item = new Node(value);
        if (!head)
        {
            head = tail = item;
        }
        else
        {
            tail->next = item;
            item->prev = tail;
            tail = item;
        }
        ++length;
    }
    void insert_front(int value)
    {
        Node *item = new Node(value);
        if (!head)
        {
            head = tail = item;
        }
        else
        {
            item->next = head;
            head->prev = item;
            head = item;
        }
        ++length;
    }
    void delete_all_nodes_with_key(int value)
    {
        if (!head)
        {
            return;
        }
        Node *cur = head;
        while (cur)
        {
            Node *nxt = cur->next;

            if (cur->data == value)
            {
                if (cur == head)
                {
                    head = head->next;
                    if (head)
                    {
                        head->prev = nullptr;
                    }
                    else
                    {
                        tail = nullptr;
                    }
                }

                else if (cur == tail)
                {
                    tail = tail->prev;
                    if (tail)
                    {
                        tail->next == nullptr;
                    }
                }
                else
                {
                    cur->prev->next = cur->next;
                    cur->next->prev = cur->prev;
                }
                delete cur;
                --length;
            }
            cur = nxt;
        }
    }

    void print()
    {
        for (Node *cur = head; cur; cur = cur->next)
            std::cout << cur->data << " ";
        std::cout << "\n";
    }
    void link(Node *first, Node *second)
    {
        if (first)
            first->next = second;
        if (second)
            second->prev = first;
    }

    ~LinkedList()
    {
        Node *cur = head;

        while (cur)
        {
            Node *nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }
};

int main()
{
    LinkedList dll;
    int len{};
    int input{};
    /*td::cin >> len;
     while(len > 0){
         std::cin >> input;
         dll.insert_back(input);
     }*/
    dll.insert_back(1);
    dll.insert_back(2);
    dll.insert_back(5);
    dll.insert_back(4);
    dll.insert_back(5);
    dll.insert_back(4);
    dll.insert_back(4);
    dll.delete_all_nodes_with_key(5);
    dll.print();
    return 0;
}