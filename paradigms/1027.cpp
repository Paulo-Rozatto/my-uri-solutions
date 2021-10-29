#include <iostream>

using namespace std;

class Node
{
public:
    short int value;
    short int frequency;
    Node *left;
    Node *right;
    Node();
    Node(short int value);
    ~Node();
};

Node::Node()
{
    this->frequency = 0;
    left = nullptr;
    right = nullptr;
}
Node::Node(short int value)
{
    this->value = value;
    this->frequency = 0;
}

Node::~Node() {}

class Tree
{
public:
    Node *root;
    int length;
    int higherFrequency;

    Tree();
    ~Tree();
    void insert(int value);
};

Tree::Tree()
{
    root = nullptr;
    higherFrequency = 0;
}

Tree::~Tree()
{
}

void Tree::insert(int value)
{
    Node *n = root;

    if (root == nullptr)
    {
        root = new Node();
        root->value = value;
        root->frequency = 1;
        length = 1;
        return;
    }

    while (n != nullptr)
    {
        if (n->value == value)
        {
            n->frequency += 1;
            if (n->frequency > higherFrequency)
                higherFrequency = n->frequency;
            break;
        }

        if (value < n->value)
        {
            if (n->left == nullptr)
            {
                n->left = new Node(value);
                n->left->frequency = 1;
                length++;

                if (n->frequency > higherFrequency)
                    higherFrequency = n->frequency;
                break;
            }

            n = n->left;
        }
        else
        {
            if (n->right == nullptr)
            {
                n->right = new Node(value);
                n->right->frequency = 1;
                length++;

                if (n->frequency > higherFrequency)
                    higherFrequency = n->frequency;
                break;
            }

            n = n->right;
        }
    }
}

class Point
{
public:
    int x;
    int y;
    Point() { x = y = 0; };
    ~Point(){};
};

int partition(Point *v, int p, int q)
{
    int pivot = v[(p + q) / 2].x;
    int i = p, j = q;
    Point aux;

    do
    {
        while (v[i].x < pivot)
            i++;
        while (v[j].x > pivot)
            j--;

        if (i <= j)
        {
            aux.x = v[i].x;
            aux.y = v[i].y;

            v[i].x = v[j].x;
            v[i].y = v[j].y;

            v[j].x = aux.x;
            v[j].y = aux.y;

            if (i < q)
                i++;
            if (j > p)
                j--;
        }

    } while (i <= j);
    return j;
}

void quickSort(Point *v, int p, int r)
{
    int q;
    if (p < r)
    {
        q = partition(v, p, r);
        quickSort(v, p, q);
        quickSort(v, q + 1, r);
    }
}

int verify(Point *p, int index, int a, int n)
{
    Point *last = &p[index];
    bool isUp = p[index].y - 1 == a;
    int cont = 1;

    for (int i = index + 1; i < n; i++)
    {
        if (p[i].x != last->x)
        {
            if (isUp)
            {
                if (p[i].y + 1 == a)
                {
                    cont++;
                    isUp = false;
                    last = &p[i];
                }
            }
            else if (p[i].y - 1 == a)
            {
                cont++;
                isUp = true;
                last = &p[i];
            }
        }
    }

    return cont;
}

int main(int argc, char const *argv[])
{
    short int n, a;
    int x, y, i, total, nUp, nDown, nPoints;

    while (cin >> n)
    {
        Tree *t = new Tree();
        Point *p = new Point[n];

        for (i = 0; i < n; i++)
        {
            cin >> x >> y;

            p[i].x = x;
            p[i].y = y;

            t->insert(y + 1);
            t->insert(y - 1);
        }
        quickSort(p, 0, n - 1);

        total = nUp = nDown = 0;

        Node *queue[t->length];
        int next = 1;

        queue[0] = t->root;

        if (t->higherFrequency == 1)
            total = 1;
        else
            for (i = 0; i < next && i < t->length; i++)
            {
                if (queue[i]->frequency > total)
                {
                    a = queue[i]->value;
                    bool up = false, down = false;
                    int j = 0;

                    while ((!up || !down) && j < n)
                    {
                        if (!up && p[j].y - 1 == a)
                        {
                            up = true;
                            nUp = verify(p, j, a, n);
                        }
                        else if (!down && p[j].y + 1 == a)
                        {
                            down = true;
                            nDown = verify(p, j, a, n);
                        }
                        j++;
                    }
                    nPoints = nUp > nDown ? nUp : nDown;
                    if (nPoints > total)
                        total = nPoints;
                }

                if (queue[i]->left != nullptr)
                {
                    queue[next] = queue[i]->left;
                    next++;
                }

                if (queue[i]->right != nullptr)
                {
                    queue[next] = queue[i]->right;
                    next++;
                }
            }
        cout << total << endl;

        delete t;
        delete[] p;
    }

    return 0;
}