#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int value);
    ~Node(){};
};

Node::Node(int value)
{
    this->value = value;
    this->next = nullptr;
}

class Stack
{
public:
    int *v;
    int n;
    int top;

    Stack(int n);
    Stack(int n, int fill);
    ~Stack();
    void insert(int value);
    int remove();

    int getTop() { return this->top > -1 ? v[top] : -1; }
};

Stack::Stack(int n)
{
    this->v = new int[n];
    this->n = n;
    this->top = -1;
}

Stack::Stack(int n, int fill)
{
    this->v = new int[n];
    this->n = n;
    this->top = -1;

    for (int i = 0, j = fill; i < n; i++, j--)
        v[i] = j;
}

Stack::~Stack()
{
    delete[] v;
}

void Stack::insert(int value)
{
    if (top < this->n - 1)
    {
        top++;
        v[top] = value;
    }
}
int Stack::remove()
{
    if (top >= 0)
    {
        int a = v[top--];
        return a;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int n, value;
    Stack *rail, *station;
    bool isPossible, found;

    while (cin >> n)
    {
        if (n == 0)
        {
            continue;
        }
        else
        {
            rail = new Stack(n, n);
            station = new Stack(n);
            value = -1;

            while (value != 0)
            {
                isPossible = true;
                found = true;
                station->top = -1;
                rail->top = n - 1;

                for (int i = 0; i < n; i++)
                {
                    cin >> value;

                    if (value == 0)
                        break;

                    if (!found)
                        continue;

                    found = false;

                    int top = station->getTop();

                    if (value == station->getTop())
                    {
                        station->remove();
                        found = true;
                    }
                    else
                    {
                        int a = rail->remove();

                        while (a != -1)
                        {
                            if (a == value)
                            {
                                found = true;
                                break;
                            }
                            station->insert(a);
                            a = rail->remove();
                        }
                    }

                    if(!found) isPossible = false;
                }

                if (value != 0)
                {
                    cout << (isPossible ? "Yes" : "No");
                }
                cout << endl;
            }
        }
    }

    return 0;
}