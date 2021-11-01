#include <iomanip>
#include <iostream>

using namespace std;

// fast enough to pass, but still to slow

class Node
{
public:
    int consume;
    int people;
    Node *left;
    Node *right;

    Node(int consume, int people);
    ~Node();
    void insert(int consume, int people);
};

Node::Node(int consume, int people)
{
    this->consume = consume;
    this->people = people;
    this->left = nullptr;
    this->right = nullptr;
}

Node::~Node()
{
    if (this->left != nullptr)
        delete this->left;
    if (this->right != nullptr)
        delete this->right;
}

void Node::insert(int consume, int people)
{
    if (consume == this->consume)
    {
        this->people += people;
    }
    else if (consume < this->consume)
    {
        if (left == nullptr)
            this->left = new Node(consume, people);
        else
            this->left->insert(consume, people);
    }
    else
    {
        if (right == nullptr)
            this->right = new Node(consume, people);
        else
            this->right->insert(consume, people);
    }
}

class Tree
{
public:
    Node *root;

    Tree();
    ~Tree();
    void insert(int consume, int people);
    void infix();

    void inHelper(Node *node);

private:
    bool printHelper;
};

Tree::Tree()
{
    this->root = nullptr;
}
Tree::~Tree()
{
    delete root;
}

void Tree::insert(int consume, int people)
{
    if (root != nullptr)
        root->insert(consume, people);
    else
        this->root = new Node(consume, people);
}

void Tree::infix()
{
    printHelper = false;
    inHelper(root);
    cout << endl;
}

void Tree::inHelper(Node *node)
{
    if (node == nullptr)
        return;

    inHelper(node->left);
    if (!printHelper)
        printHelper = true;
    else
        cout << " ";
    cout << node->people << "-" << node->consume;
    inHelper(node->right);
}

int main(int argc, char const *argv[])
{
    int n, x, y, cityCont = 1;
    float peopleCont, consumeCont;
    Tree *t;

    cin >> n;

    do
    {
        if (cityCont > 1)
            cout << endl;
        cout << "Cidade# " << cityCont++ << ":" << endl;

        t = new Tree();

        peopleCont = consumeCont = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            t->insert(y / x, x);
            peopleCont += x;
            consumeCont += y;
        }
        t->infix();

        consumeCont /= peopleCont;
        string s = to_string(consumeCont);
        s = s.substr(0, s.length() - 4);

        cout << "Consumo medio: ";
        cout << s << " m3." << endl;

        delete t;

        cin >> n;
    } while (n > 0);

    return 0;
}