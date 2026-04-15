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
    void swap_pairs()
    {
        if (!head || !head->next)
            return;
        if (length == 2)
        {
            Node *first = head;
            Node *second = head->next;
            first->next = second->next;
            second->next = first;
            head = second;
        }
        if (length == 3)
        {
            Node *cur = head;
            Node *nxt = cur->next;
            while (cur && cur->next)
            {
                Node *third = nxt->next;
                if (!third)
                    break;
                head = nxt;
                third->next = cur;
                cur->next = nullptr;
                tail = cur;
                return;
            }
        }
    }
    void swap_two_pairs (){
        if (!head || !head->next) return;
        Node* cur = head;
        Node* nxt = cur->next;
        int temp = -1; 
        while(nxt->next&&cur->next){
            temp = cur->data;
            cur->data = nxt->data;
            nxt->data = temp;

            //move
            if(nxt->next != nullptr && nxt->next->next != nullptr) {
                nxt = nxt->next->next;
            }
            
              if(cur->next != nullptr && cur->next->next != nullptr) {
                cur = cur->next->next;
            }
            
        }
    }
    /*
    
    void swap_two_pairs() {
    if (!head || !head->next) return;

    Node* cur = head;

    while (cur && cur->next) {
        Node* nxt = cur->next;

        // swap data
        int temp = cur->data;
        cur->data = nxt->data;
        nxt->data = temp;

        // move to next pair
        cur = cur->next->next;
    }
}*/
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
    int n{};
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        sll.insert_back(x);
    }
    sll.swap_two_pairs();
    sll.print();
    return 0;
}