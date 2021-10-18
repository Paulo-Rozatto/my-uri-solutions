#include <iostream>
#include <list>

using namespace std;

class Node
{
public:
    char value;
    Node *next;
    Node *prev;
    Node(char value);
    ~Node();
};

Node::Node(char value)
{
    this->value = value;
    this->next = nullptr;
}

Node::~Node()
{
}

class List
{
public:
    Node *top;
    Node *bottom;
    int length;
    int removes;

    List(int digits, int removes);
    ~List() {}
    void insert(char value);
    void remove(Node *n, Node *prev);
};
List::List(int digits, int removes)
{
    top = nullptr;
    this->removes = removes;
    length = 0;
};

void List::insert(char value)
{
    int i;
    char helper = value;
    int size = length;
    int rm = removes;

    Node *n;
    for (n = top; n != nullptr; n = n->next)
    {
        if (n->value < value && removes > 0)
        {
            top = n->next;
            removes--;
            length--;
        }
        else
        {
            break;
        }
    }

    n = new Node(value);
    n->next = top;
    if (top != nullptr)
        top->prev = n;
    top = n;
    if (length == 0)
        bottom = top;
    length++;
}

void List::remove(Node *n, Node *prev)
{
}

int main(int argc, char const *argv[])
{
    int *numb;
    int length, d;
    char c;
    List *l;
    Node *n, *prev;

    std::cin >> length >> d;

    while (length != 0 || d != 0)
    {
        l = new List(length, d);

        for (int i = 0; i < length; i++)
        {
            std::cin >> c;
            l->insert(c);
        }
        l->length -= l->removes;

        n = l->bottom;
        for (int i = 0; i < l->length; i++)
        {
            cout << n->value;
            n = n->prev;
        }
        cout << endl;

        delete l;
        std::cin >> length >> d;
    }

    return 0;
}