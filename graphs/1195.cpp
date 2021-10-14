#include <iostream>

using namespace std;

// Arvore binaria de busca

class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int value);
    ~Node();
    void insert(int value);
};

Node::Node(int value)
{
    this->value = value;
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

void Node::insert(int value)
{
    if (value < this->value)
    {
        if (left == nullptr)
            this->left = new Node(value);
        else
            this->left->insert(value);
    }
    else
    {
        if (right == nullptr)
            this->right = new Node(value);
        else
            this->right->insert(value);
    }
}

class Tree
{
public:
    Node *root;

    Tree();
    ~Tree();
    void insert(int value);
    void prefix();
    void infix();
    void posfix();

    void preHelper(Node *node, int i);
    void inHelper(Node *node, string *v);
    void posHelper(Node *node, string *v);
};

Tree::Tree()
{
    this->root = nullptr;
}
Tree::~Tree()
{
    delete root;
}

void Tree::insert(int value)
{
    if (root != nullptr)
        root->insert(value);
    else
        this->root = new Node(value);
}

void Tree::prefix()
{
    preHelper(root, 0);
    cout << endl;
}

void Tree::preHelper(Node *node, int i)
{
    if (node == nullptr)
        return;

    if (i > 0)
        cout << " ";

    cout << node->value;

    preHelper(node->left, i + 1);
    preHelper(node->right, i + 1);
}

void Tree::infix()
{
    string v;
    inHelper(root, &v);
    cout << v.substr(0, v.length() - 1) << endl;
}

void Tree::inHelper(Node *node, string *v)
{
    if (node == nullptr)
        return;

    inHelper(node->left, v);
    *v += to_string(node->value);
    *v += " ";
    inHelper(node->right, v);
}

void Tree::posfix()
{
    string v;
    posHelper(root, &v);
    cout << v.substr(0, v.length() - 1) << endl;
}

void Tree::posHelper(Node *node, string *v)
{
    if (node == nullptr)
        return;

    posHelper(node->left, v);
    posHelper(node->right, v);
    *v += to_string(node->value);
    *v += " ";
}

int main(int argc, char const *argv[])
{
    int cases, size, value;
    Tree *tree;

    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        cin >> size;

        tree = new Tree();

        for (int j = 0; j < size; j++)
        {
            cin >> value;

            tree->insert(value);
        }
        cout << "Case " << (i + 1) << ":" << endl;
        cout << "Pre.: ";
        tree->prefix();

        cout << "In..: ";
        tree->infix();

        cout << "Post: ";
        tree->posfix();

        cout << endl;

        delete tree;
    }

    return 0;
}