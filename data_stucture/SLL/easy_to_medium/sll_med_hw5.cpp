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
    void delete_node_with_key(int value)
    {
        if (!head)
            return; // empty list

        if (head->data == value)
        {
            delete_first();
            return;
        }
        Node *prev = head;
        Node *cur = head->next;

        while (cur)
        {
            if (cur->data == value)
            {
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

    void insert_sorted(int value)
    {
        Node *cur = head;
        Node *prev = nullptr;
        Node *item = new Node(value);
        if (!head || value <= head->data)
        {
            item->next = head;
            head = item;
            ++length;
            return;
        }
        
        while(cur && cur->next){
            if(item->data <= cur->data){
                prev->next = item;
                item->next = cur;
                prev = item;
                ++length;
                return;
            }
            prev = cur;
            cur = cur->next;
        }

        cur->next = item;
        item->next = nullptr;
        ++length;
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
    int len = 0;
    std::cin >> len;
    while (len > 0)
    {
        int input{};
        std::cin >> input;
        sll.insert_back(input);
        --len;
    }
    sll.insert_sorted(11);
    sll.print();
    return 0;
}