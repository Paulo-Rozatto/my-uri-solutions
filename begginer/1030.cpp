#include <iostream>
#include <list>
#include <iterator>

using namespace std;

class Node
{
public:
    Node *previous, *next;
    int value;
    static int size;

    Node(int value)
    {
        next = NULL;
        previous = NULL;
        this->value = value;
        size++;
    }
    Node(int value, int n)
    {
        next = NULL;
        previous = NULL;
        this->value = value;
        size++;
        populate(1, n, NULL, this);
    }

    void setNext(Node *next)
    {
        this->next = next;
    }

    void populate(int s, int n, Node *previous, Node *first)
    {
        this->previous = previous;
        if (s < n)
        {
            next = new Node(value + 1);
            next->populate(s + 1, n, this, first);
        }
        else
        {
            next = first;
            first->previous = this;
        }
    }

    void show(int n)
    {

        if (next && n)
        {
            cout << value << " ";
            next->show(n - 1);
            // previous->show(n - 1);
        }
        else
            cout << endl;
    }

    Node *remove(int k)
    {
        Node *n, *tag;
        while (k-- > 1)
        {
            n = next;
        }
        // cout << n->value << endl;
        tag = n->next;
        n->previous->next = tag;
        free(n);
        size--;
        return tag;
    }
};

int Node::size = 0;

int main(int argc, char const *argv[])
{
    int n, k;

    cin >> n >> k;

    Node *node = new Node(1, n);

    while (Node::size > 0)
    {
        // Node node2 = node.remove(k);
        node = node->remove(k);
        // node->show(Node::size);
        // cout << endl << node->value << endl << endl;
    }

    cout << node->value << endl;

    return 0;
}